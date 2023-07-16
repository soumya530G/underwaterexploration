class init:
    @staticmethod
    def weights():
        import urllib.request
        url = 'https://pjreddie.com/media/files/yolov3.weights'
        file_name = url.split('/')[-1]

        urllib.request.urlretrieve(url, file_name)
