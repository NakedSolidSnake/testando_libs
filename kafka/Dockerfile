FROM ubuntu

RUN apt-get update && apt-get install pip cmake g++ -y

RUN pip install conan==1.59

WORKDIR /development

ENTRYPOINT [ "/bin/tail", "-f", "/dev/null" ]
