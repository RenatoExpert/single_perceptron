FROM gcc:14.2
WORKDIR /app
COPY . .
RUN gcc neuron.c -o neuron
ENTRYPOINT ["./neuron"]

