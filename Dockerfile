FROM ocaml/opam:alpine-3.19-ocaml-5.1 as builder

RUN sudo apk update && sudo apk add --update nodejs npm

WORKDIR /home/opam

COPY snake-reason-game.opam snake-reason-game.opam
# COPY --chown=opam:opam . .

RUN npm install && \
  opam update && \
  opam install -y . --deps-only && \
  opam exec -- dune build @react @node && \
  npm run bundle


# Use a smaller image for production
FROM nginx:alpine

WORKDIR /usr/share/nginx/html

# Copy the built app from the builder stage
COPY --from=builder /home/opam/dist ./

# Expose the default port for nginx
# EXPOSE 8080

# Start nginx
CMD ["nginx", "-g", "daemon off;"]

