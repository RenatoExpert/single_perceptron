FROM gcc:14.2 AS compile
WORKDIR /app
COPY . .
RUN gcc neuron.c -o neuron

FROM scratch AS run
COPY --from=compile /app/neuron . 
ENTRYPOINT ["./neuron"]

