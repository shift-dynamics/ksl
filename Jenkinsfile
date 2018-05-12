pipeline {
  agent any

  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'mkdir build && cd build && cmake .. && make && cd ..'
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
