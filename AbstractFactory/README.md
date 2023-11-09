# Abstract Factory
- Based on "Design Patterns: Elements of Reusable Object-Oriented Software" by Erich Gamma

## 요약
instance의 생성(instantiaton)을 담당하는 별도의 interface(abstract factory)를 정의해, class의 구현(implementation)과 별도로 사용할 수 있게 만듦

### 배경
스마트폰의 각 부품들을 클래스로 만든다고 생각해보자.
스마트폰이 Chipset, Camera, MemoryCard 세 가지 Class로 구성된다고 했을 때,
갤럭시의 부품들은 갤럭시 부품끼리만, 아이폰의 부품들은 같은 아이폰 부품끼리만 호환이 될 것이다.

```
class Chipset
{
    public Chipset()
    {
            
    }
}

class Camera
{
    public Camera()
    {
            
    }
}
class MemoryCard
{
    public MemoryCard()
    {
        
    }
}
```
그렇다면 GalaxyChipset, GalaxyCamera, GalaxyMemoryCard, IphoneChipset, IphoneCamera, IphoneMemoryCard클래스가 필요할 것이다. 
```
class GalaxyChipset: Chipset
{
    public GalaxyChipset()
    {
            
    }
}
/*  ...  */
class IphoneMemoryCard : MemoryCard
{
    public IphoneMemoryCard()
    {
        
    }
}
```
```
    static void Main()
    {
        GalaxyChipset galaxyChipset = new GalaxyChipset();
        GalaxyCamera galaxyCamera = new GalaxyCamera();
        GalaxyMemoryCard galaxyMemoryCard = new GalaxyMemoryCard();

        IphoneCamera iphoneCamera = new IphoneCamera();
        IphoneChipset iphoneChipset = new IphoneChipset();
        IphoneMemoryCard iphoneMemoryCard = new IphoneMemoryCard();
    }
```
부품 클래스들을 각각 생성한다면 새로운 회사의 스마트폰이 생길 때마다 이를 생성하는 코드를 작성해주어야 한다.

## 구현
서로 관련된 class들을 한번에 생성하는 abstract factory interface를 정의하면 보다 간편하게 구성할 수 있다.
```
interface IAbstractFactory
{
public:
    virtual Chipset* MakeChipSet() const{ return new Chipset; }
    virtual Camera* MakeCamera() const{ return new Camera; }
    virtual MemoryCard* MakeMemoryCard() const{ return new MemoryCard; }
}

class GalaxyFactory : IAbstractFactory
{
public:
    virtual Chipset* MakeChipSet() const{ return new GalaxyChipset; }
    virtual Camera* MakeCamera() const{ return new GalaxyCamera; }
    virtual MemoryCard* MakeMemoryCard() const{ return new GalaxyMemoryCard; }
}

public SmartPhone* MakeSmartPhone(IAbstractFactory& factory){
    Chipset* chipset = factory.MakeChipSet();
    Camera* camera = factory.MakeCamera();
    MemoryCard* memoryCard = factory.MakeMemoryCard();
    
    SmartPhone* smartPhone = new SmartPhone(chipset, camera, memoryCard);
    return smartPhone;
}
```
MakeSmartPhone 함수에 Factory를 인자로 줌으로써 적합한 부품만 사용해 스마트폰 클래스를 구성할 수 있다.
