FROM gcc:4.9
WORKDIR /app
COPY . .
RUN gcc neuron.c -o neuron
CMD ["./neuron"]

