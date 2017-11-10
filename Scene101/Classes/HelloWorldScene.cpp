#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::~HelloWorld()
{

#if EXERCISE == 1
	_jumpAction->release(); // �]���Q�O�d�n�D������
#endif

}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);

#if EXAMPLES == 1
// ���ĻP���� --------------------------------------------------------------------------------
	auto bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("bkmusic")->getComponent("bkmusic"); // �p�G��cocos-2d �s�边��J����
	bkmusic->playBackgroundMusic(); // �p�G��cocos-2d �s�边��J����

	//SimpleAudioEngine::getInstance()->playBackgroundMusic("./music/SR_bg.mp3", true);
	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2f);  //�|����@
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();	// ����I������
	SimpleAudioEngine::getInstance()->preloadEffect("thinking cloud.mp3");	// �w�����J������
	unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3",true);  // ���񭵮���
	//SimpleAudioEngine::getInstance()->stopEffect(eid);  // ����ļ���A�����ϥ� PlayEffect �Ǧ^�� id
	//SimpleAudioEngine::getInstance()->unloadEffect("thinking cloud.mp3");  // ���񭵮���
//---------------------------------------------------------------------------------------------

#elif EXAMPLES == 2
// Sprite ------------------------------------------------------------------------------------- 
#if EXERCISE == 0
	auto runner = (cocos2d::Sprite *)rootNode->getChildByName("cuber01");
	runner->setColor(Color3B(75,155,77));
	Point pt = runner->getPosition();
	auto jumpAction = cocos2d::JumpTo::create(1.25f, Point(pt.x - 600, pt.y), 100, 3); // (�Ҫ�ɶ�,�ت��a,����,����)
	auto tintTo = cocos2d::TintTo::create(1.25f, Color3B(50, 125, 250)); // ���ܦ�m
	runner->runAction(tintTo); // ����!!
	runner->runAction(jumpAction);
#elif EXERCISE == 1
	//  ------ �Ұ�m�ߤ@  ------
	_runner = (cocos2d::Sprite *)rootNode->getChildByName("cuber01");
	_runner->setColor(Color3B(75, 155, 77));
	Point pt = _runner->getPosition();
	_jumpAction = cocos2d::JumpTo::create(1.25f, Point(pt.x - 600, pt.y), 100, 3);
	_jumpAction->retain(); // �O�d���Q���� because creat�|�۰ʧ⥼�ΪF������ �̫�n�O�o�ۤv����!

	Button *cuberbtn = dynamic_cast<Button*>(rootNode->getChildByName("CuberBtn")); // dynamic_cast�|���A�ˬd���O
	cuberbtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::CuberBtnTouchEvent, this)); // touch�ƥ� �I�s�禡

#endif

//---------------------------------------------------------------------------------------------		

#elif EXAMPLES == 3
// Button -------------------------------------------------------------------------------------
	Button *cuberbtn = dynamic_cast<Button*>(rootNode->getChildByName("CuberBtn")); // dynamic_cast�|���A�ˬd���O
	//Button *cuberbtn = (cocos2d::ui::Button *)(rootNode->getChildByName("CuberBtn")); // �P�W�@��P�\��  �ŧi�Φb�w�����O���A�U(���|�ˬd)
	cuberbtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::CuberBtnTouchEvent, this)); // touch�ƥ� �I�s�禡
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 4
// �奻 TTF �r��-------------------------------------------------------------------------------
	auto text = (cocos2d::ui::Text *)rootNode->getChildByName("Text101");
	text->setColor(Color3B(200, 255, 50));

//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 5
// CheckBox-------------------------------------------------------------------------------
	CheckBox *checkBox = dynamic_cast<CheckBox*>(rootNode->getChildByName("CheckBox_1"));
////CheckBox *checkBox = (cocos2d::ui::CheckBox*)(rootNode->getChildByName("CheckBox_1"));
	checkBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxTouchEvent, this));
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 6
// FNT �r��-------------------------------------------------------------------------------
	auto bmtlabel = (cocos2d::Label *)rootNode->getChildByName("BMFont");
	bmtlabel->setColor(Color3B(200, 255, 50));
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 7
// loadingBar -------------------------------------------------------------------------------
#if EXERCISE != 2
	auto loadingBar = (cocos2d::ui::LoadingBar *)rootNode->getChildByName("LoadingBar_1");
	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setPercent(50);
#else 
	_loadingBar = (cocos2d::ui::LoadingBar *)rootNode->getChildByName("LoadingBar_1");
	_loadingBar->setDirection(LoadingBar::Direction::RIGHT);
	_loadingBar->setPercent(100);
#endif
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 8
// Slider �ưʱ� -------------------------------------------------------------------------------------
	auto *slider = (cocos2d::ui::Slider *)(rootNode->getChildByName("Slider_1"));
	slider->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
	slider->setPercent(50);
	slider->setMaxPercent(100);		// �i�H�]�w�W�L 100�A���W�L100�|�����ʶs����ܷ|�����D
	// �H�U�Ω� slider ��ܥ�
	_sliderValue = (cocos2d::ui::Text *)rootNode->getChildByName("Text101");
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 9
//// �ǦC�V�ʵe -------------------------------------------------------------------------------------
	auto runner = (cocos2d::Sprite *)rootNode->getChildByName("Sprite_1");
	runner->setColor(Color3B(135, 250, 50));
	auto action = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	rootNode->runAction(action);
	action->gotoFrameAndPlay(0, 24, true);
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 10
// Ū�J�P����զX�����ǦC�V�ʵe
	auto triRoot1 = CSLoader::createNode("triangleNode.csb");
	triRoot1->setPosition(100, 360);
	this->addChild(triRoot1);

	auto triAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	triRoot1->runAction(triAction);
	triAction->setDuration(3.0f);
	triAction->gotoFrameAndPlay(0, 35, false);

	// _triRoot2 ���ʵe����b���U�ù���Ұ�
	_triRoot2 = CSLoader::createNode("triangleNode.csb");
	_triRoot2->setPosition(300, 360);
	this->addChild(_triRoot2);
	_triAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	_triAction->setDuration(2.0f);
	_triRoot2->runAction(_triAction);
//---------------------------------------------------------------------------------------------	

// �H�U�[�J������ TouchBegan �ƥ�
	//_triAction->gotoFrameAndPlay(0, 35, false);
//---------------------------------------------------------------------------------------------	

#endif

	_listener1 = EventListenerTouchOneByOne::create();	//�Ыؤ@�Ӥ@��@���ƥ��ť��
	_listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);		//�[�JĲ�I�}�l�ƥ�
	_listener1->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);		//�[�JĲ�I���ʨƥ�
	_listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);		//�[�JĲ�I���}�ƥ�

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//�[�J��Ыت��ƥ��ť��

// �N doStep �禡���J schedule list ���A�C�@�� frame �N���|�Q�I�s��
	this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::doStep));
	return true;
}


void HelloWorld::doStep(float dt)
{
#if EXERCISE == 2 //�Ұ�m�ߤG �C��5%
	float t = _loadingBar->getPercent();
	if (t >= dt * 5 )  t = t - dt *5;
	else t = 0;
	_loadingBar->setPercent(t);
#else

#endif
}

void HelloWorld::CuberBtnTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		case Widget::TouchEventType::BEGAN:
			log("Touch Down"); // cocos-2d �s�边�i���ܤ�
			break;
		case Widget::TouchEventType::MOVED:
			log("Touch Move");
			break;
		case Widget::TouchEventType::ENDED:
			log("Touch Up");

#if EXERCISE == 1
			_runner->runAction(_jumpAction);
#endif
			break;
		case Widget::TouchEventType::CANCELED: // ���U�Ჾ�}��m��}
			log("Touch Cancelled");
			break;
		default:
			break;
	}
}

void HelloWorld::checkBoxTouchEvent(Ref* object, CheckBox::EventType type) {
	switch (type)
	{
	case CheckBox::EventType::UNSELECTED:
		log("Unselected");
		break;

	case CheckBox::EventType::SELECTED:
		log("Selected");
		break;

	}
}


void HelloWorld::sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		Slider* slider = dynamic_cast<Slider*>(sender);
		int percent = slider->getPercent();
		int maxPercent = slider->getMaxPercent();
		_sliderValue->setString(StringUtils::format("Percent %5.2f", 100.0 * percent / maxPercent));
	}
}

bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//Ĳ�I�}�l�ƥ�
{
	Point touchLoc = pTouch->getLocation();

	_triAction->gotoFrameAndPlay(0, 35, false);
	
	return true;
}

void  HelloWorld::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I���ʨƥ�
{
	Point touchLoc = pTouch->getLocation();
}

void  HelloWorld::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I�����ƥ� 
{
	Point touchLoc = pTouch->getLocation();
}