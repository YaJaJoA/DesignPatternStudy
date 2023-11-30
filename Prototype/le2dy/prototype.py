from copy import deepcopy
# 코드 컨셉을 위한 클래스
class Image():
    def __init__(self, OS:str, name:str,*options) -> None:
        self.os = OS
        self.imageName = name
        self.options = options
        pass
    def getInfo(self):
        return {"OS": self.os, "Image Name": self.imageName, "Options": self.options}

# protoype으로 복제할 클래스
class Pod():
    packages = []
    def __init__(self, image: Image, _pod = None) -> None:
        self.image = image
        if _pod:
            self.packages = deepcopy(_pod.packages)
        pass

    # 새 Pod 클래스를 생성하는 clone 메소드 구현
    def clone(self):
        return Pod(self.image,self)
    def addPackage(self, packageName: str):
        self.packages.append(packageName)
    def packageList(self):
        return self.packages
    def getImageInfo(self):
        return self.image.getInfo()
    
# 입력받은 Pod 클래스를 복제할 Prototype 클래스
class PodPrototype():
    def __init__(self,p: Pod) -> Pod:
        self._Pod = p

    # clone 메소드를 구현해 입력받은 Pod 클래스를 복제
    def clone(self):
        return self._Pod.clone()
    
if __name__ == "__main__":
    img = Image("centos7", "CICD")
        
    # 복제할 Pod 객체 생성
    p = Pod(img)
    # Pod에 페키지 추가
    p.addPackage("Node")
    p.addPackage("sl")
    p.addPackage("python3")

    # prototype 객체 생성
    prototype = PodPrototype(p)

    # clone 메소드로 Pod 객체 복사
    pod1 = prototype.clone()
    pod2 = prototype.clone()
    # pod1과 pod2가 다른 객체인 것을 확인하기 위해 pod1에 패키지 추가
    pod1.addPackage("tensorflow")

    # 내부의 패키지 리스트 출력
    print(pod1.packageList())
    print(pod2.packageList())

    print(pod1.getImageInfo())

    