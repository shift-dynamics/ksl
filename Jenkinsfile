pipeline {
  agent any

  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'rm build && mkdir -p build && cd build && cmake .. && make && cd ..'
      }
    }
    stage('Test') {
      steps {
        echo 'Testing..'
        sh 'cd build'
        sh 'make test || true'
      }
    }
  }
}
