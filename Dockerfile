FROM gcc:14.2 AS compile
WORKDIR /app
COPY . .
RUN gcc -static neuron.c -o neuron

FROM scratch AS run
WORKDIR /app
COPY --from=compile /app/neuron neuron
ENTRYPOINT ["/app/neuron"]

