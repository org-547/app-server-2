name: Backend workflow

on:
  push:
    branches: ["main"]

jobs:
  Image-build-push:
    name: Job1
    runs-on: ubuntu-latest

    steps:
      - name: Use custom action
        uses: org-547/app-2-actions/job-1@main
        with:
          app-component: app-server-2
          container: back-cnt
          port: 5000
          docker-uname: ${{ secrets.DOCKER_UNAME }}
          docker-token: ${{ secrets.DOCKER_TOKEN }}
  
  Change-image-tag-and-deploy:
    name: Job2
    needs: [Image-build-push]
    runs-on: self-hosted

    steps:
      - name: Use another custom action
        uses: org-547/app-2-actions/job-2@main
        with:
          git-user: 'Tereza'
          email: 'an3146073@gmail.com'
          ssh-priv-key: ${{ secrets.SSH_PRIV_KEY }}
          app-component: 'app-server-2'
          git-token: ${{ secrets.GIT_TOKEN }}
          second-component-tag: 'undefined-front-tag'
    
