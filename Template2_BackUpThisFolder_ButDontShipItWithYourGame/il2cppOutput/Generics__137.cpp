#include "pch-cpp.hpp"





template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};

struct IEnumerator_1_tFF72DC851BEBD20B537316531A651EA6D9113F07;
struct IEnumerator_1_tC3DA6B4DE5C905620A6561C1B4B4ABAE3567CFDF;
struct IEnumerator_1_t5DAD8BCEA32C5A575380EC8FE46A7E33C284AB9B;
struct IEnumerator_1_tB6FE08547500D274CF67F20EE02F82580D4BC22C;
struct IEnumerator_1_tC468DB891870F3A93D33674D3D64678048EAD8B9;
struct IEnumerator_1_t23FAA0070CF44C0B169AD8559E586AB92C63FD52;
struct IEnumerator_1_t67337D985DBE9BFBDFC3C90B9F73A8F2419B53C1;
struct IEnumerator_1_t4E8BE0F247DFAF4E9E75E616123C59813D05C28D;
struct IEnumerator_1_t22C1ED2DAB08995CC23BE65441E55E5A459816DB;
struct IEnumerator_1_t6112577D77319B336CCA0143431A5C19E4592875;
struct Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D;
struct Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D;
struct Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6;
struct Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722;
struct Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03;
struct Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC;
struct Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE;
struct Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F;
struct Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4;
struct Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB;
struct RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D;
struct RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669;
struct RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56;
struct TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7;
struct TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08;
struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA;
struct NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D;
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3;
struct TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB;
struct TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989;
struct RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8;
struct ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243;
struct SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221;
struct SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3;
struct SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483;
struct TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F;
struct TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC;
struct TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80;
struct VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
struct Exception_t;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE;
IL2CPP_EXTERN_C String_t* _stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4;
IL2CPP_EXTERN_C String_t* _stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70;
IL2CPP_EXTERN_C String_t* _stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8;
IL2CPP_EXTERN_C String_t* _stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8;
IL2CPP_EXTERN_C String_t* _stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA;
struct NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D;
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3;
struct TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989;
struct RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8;
struct ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243;
struct SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221;
struct SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3;
struct SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483;
struct TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F;
struct TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC;
struct TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80;
struct VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EmptyArray_1_tDA1E10579FDDCE25837B4F203EABDCA5251082FB  : public RuntimeObject
{
};
struct EmptyArray_1_tFF1C726B7AD2D4CB615066440DB2BD360077F74E  : public RuntimeObject
{
};
struct EmptyArray_1_t151CEED89EBC00271F4BF4ACC9D4E781D780866E  : public RuntimeObject
{
};
struct EmptyArray_1_tBA9A911B01CFC769E520FBF101B83CC77C18ECCF  : public RuntimeObject
{
};
struct EmptyArray_1_tDEA777902FAFA73B2D66B35576B82407F616798F  : public RuntimeObject
{
};
struct EmptyArray_1_t45ACA127E94E3425602D4677D3A2A8DF9A62AC4C  : public RuntimeObject
{
};
struct EmptyArray_1_t2AEFF5629DF828443FB4E93984DDA89352CA99D9  : public RuntimeObject
{
};
struct EmptyArray_1_t2B80EF52C4FCF840DBDC03E7CBF5D78B21674522  : public RuntimeObject
{
};
struct EmptyArray_1_t3014CE3C51BB8D288EE928901E5BE2DE487639F7  : public RuntimeObject
{
};
struct EmptyArray_1_tB72192C297310B25DA15BD93F344C7BD7F1E0DBC  : public RuntimeObject
{
};
struct Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D  : public RuntimeObject
{
	RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D  : public RuntimeObject
{
	RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6  : public RuntimeObject
{
	ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722  : public RuntimeObject
{
	SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03  : public RuntimeObject
{
	SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC  : public RuntimeObject
{
	SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE  : public RuntimeObject
{
	TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F  : public RuntimeObject
{
	TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4  : public RuntimeObject
{
	TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB  : public RuntimeObject
{
	VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* ____array;
	int32_t ____head;
	int32_t ____tail;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7  : public RuntimeObject
{
	NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* ____slots;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____slotMap;
	int32_t ____inUseCount;
	int32_t ____pageId;
	int32_t ____nextFreeSlotLine;
};
struct TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08  : public RuntimeObject
{
	NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* ____slots;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____slotMap;
	int32_t ____inUseCount;
	int32_t ____pageId;
	int32_t ____nextFreeSlotLine;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 
{
	int32_t ____nodeID;
	int32_t ____mainTreeNodeID;
};
struct NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 
{
	int32_t ____nodeID;
	int32_t ____mainTreeNodeID;
};
struct RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 
{
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ____tree;
	int32_t ____version;
	int32_t ____index;
	int32_t ____mainTreeNodeId;
	int32_t ____current;
};
struct RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A 
{
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ____tree;
	int32_t ____version;
	int32_t ____index;
	int32_t ____mainTreeNodeId;
	RuntimeObject* ____current;
};
typedef Il2CppFullySharedGenericStruct RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4;
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_marshaled_pinvoke
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_marshaled_com
{
	ParticleSystem_tB19986EE308BD63D36FB6025EEEAFBEDB97C67C1* ___m_ParticleSystem;
};
struct Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 
{
	Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* ____q;
	int32_t ____version;
	int32_t ____index;
	RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 ____currentElement;
};
struct Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 
{
	Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* ____q;
	int32_t ____version;
	int32_t ____index;
	RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 ____currentElement;
};
struct Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C 
{
	Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* ____q;
	int32_t ____version;
	int32_t ____index;
	ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 ____currentElement;
};
struct Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 
{
	Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* ____q;
	int32_t ____version;
	int32_t ____index;
	SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 ____currentElement;
};
struct Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 
{
	Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* ____q;
	int32_t ____version;
	int32_t ____index;
	SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C ____currentElement;
};
struct Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 
{
	Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* ____q;
	int32_t ____version;
	int32_t ____index;
	SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B ____currentElement;
};
struct Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B 
{
	Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* ____q;
	int32_t ____version;
	int32_t ____index;
	TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 ____currentElement;
};
struct Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 
{
	Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* ____q;
	int32_t ____version;
	int32_t ____index;
	TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D ____currentElement;
};
struct Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 
{
	Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* ____q;
	int32_t ____version;
	int32_t ____index;
	TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 ____currentElement;
};
struct Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 
{
	Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* ____q;
	int32_t ____version;
	int32_t ____index;
	VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 ____currentElement;
};
struct NodeColor_t60CC6B48EF16CC76598762EF71BFEABD73151911 
{
	int32_t ___value__;
};
struct NodeColor_tC8EFC0D9ADE3D859539E5AE7AB7DEFDF7C8332DB 
{
	int32_t ___value__;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct RBTreeError_t7F1B2496C83326D0832CBD24FB32282F348CD048 
{
	int32_t ___value__;
};
struct TreeAccessMethod_t93F641AE9C014E6ABDD0A2B1EA84068077F46CC5 
{
	int32_t ___value__;
};
struct Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 
{
	int32_t ____selfId;
	int32_t ____leftId;
	int32_t ____rightId;
	int32_t ____parentId;
	int32_t ____nextId;
	int32_t ____subTreeSize;
	int32_t ____keyOfNode;
	int32_t ____nodeColor;
};
struct Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB 
{
	int32_t ____selfId;
	int32_t ____leftId;
	int32_t ____rightId;
	int32_t ____parentId;
	int32_t ____nextId;
	int32_t ____subTreeSize;
	RuntimeObject* ____keyOfNode;
	int32_t ____nodeColor;
};
struct RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D  : public RuntimeObject
{
	TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669  : public RuntimeObject
{
	TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56  : public RuntimeObject
{
	TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	RuntimeObject* ____actualValue;
};
struct EmptyArray_1_tDA1E10579FDDCE25837B4F203EABDCA5251082FB_StaticFields
{
	RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* ___Value;
};
struct EmptyArray_1_tFF1C726B7AD2D4CB615066440DB2BD360077F74E_StaticFields
{
	RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* ___Value;
};
struct EmptyArray_1_t151CEED89EBC00271F4BF4ACC9D4E781D780866E_StaticFields
{
	ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* ___Value;
};
struct EmptyArray_1_tBA9A911B01CFC769E520FBF101B83CC77C18ECCF_StaticFields
{
	SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* ___Value;
};
struct EmptyArray_1_tDEA777902FAFA73B2D66B35576B82407F616798F_StaticFields
{
	SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* ___Value;
};
struct EmptyArray_1_t45ACA127E94E3425602D4677D3A2A8DF9A62AC4C_StaticFields
{
	SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* ___Value;
};
struct EmptyArray_1_t2AEFF5629DF828443FB4E93984DDA89352CA99D9_StaticFields
{
	TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* ___Value;
};
struct EmptyArray_1_t2B80EF52C4FCF840DBDC03E7CBF5D78B21674522_StaticFields
{
	TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* ___Value;
};
struct EmptyArray_1_t3014CE3C51BB8D288EE928901E5BE2DE487639F7_StaticFields
{
	TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* ___Value;
};
struct EmptyArray_1_tB72192C297310B25DA15BD93F344C7BD7F1E0DBC_StaticFields
{
	VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* ___Value;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989  : public RuntimeArray
{
	ALIGN_FIELD (8) RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 m_Items[1];

	inline RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8  : public RuntimeArray
{
	ALIGN_FIELD (8) RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 m_Items[1];

	inline RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243  : public RuntimeArray
{
	ALIGN_FIELD (8) ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 m_Items[1];

	inline ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221  : public RuntimeArray
{
	ALIGN_FIELD (8) SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 m_Items[1];

	inline SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3  : public RuntimeArray
{
	ALIGN_FIELD (8) SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C m_Items[1];

	inline SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483  : public RuntimeArray
{
	ALIGN_FIELD (8) SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B m_Items[1];

	inline SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F  : public RuntimeArray
{
	ALIGN_FIELD (8) TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 m_Items[1];

	inline TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC  : public RuntimeArray
{
	ALIGN_FIELD (8) TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D m_Items[1];

	inline TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80  : public RuntimeArray
{
	ALIGN_FIELD (8) TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 m_Items[1];

	inline TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734  : public RuntimeArray
{
	ALIGN_FIELD (8) VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 m_Items[1];

	inline VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
	inline VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_ParticleSystem), (void*)NULL);
	}
};
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3  : public RuntimeArray
{
	ALIGN_FIELD (8) TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* m_Items[1];

	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA  : public RuntimeArray
{
	ALIGN_FIELD (8) Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 m_Items[1];

	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 value)
	{
		m_Items[index] = value;
	}
};
struct TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB  : public RuntimeArray
{
	ALIGN_FIELD (8) TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* m_Items[1];

	inline TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D  : public RuntimeArray
{
	ALIGN_FIELD (8) Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB m_Items[1];

	inline Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____keyOfNode), (void*)NULL);
	}
	inline Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____keyOfNode), (void*)NULL);
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m3EE7DDC17C8BF4A848530E14BE83AB2FF51EAD72_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132_gshared (Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7* __this, Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D_gshared (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* ___0_array, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m06D7B5BE55FEF9235CFA3C383C4CD74A3DEC4792_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8_gshared (Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922* __this, Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE_gshared (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* ___0_array, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m7B994227375B3265506AD6D468B9FFBC4C1FC3BA_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D_gshared (Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C* __this, Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE_gshared (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* ___0_array, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mF2AC2CA3FB3A64549B30ABD823DAA8FF2D5FEC42_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8_gshared (Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57* __this, Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7_gshared (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* ___0_array, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m9165403F0F0F7767662F23A1A6235E06D807D5CF_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253_gshared (Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920* __this, Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629_gshared (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* ___0_array, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m6B2C5C5826028020475F98EF83010A8CC0EF0594_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376_gshared (Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696* __this, Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246_gshared (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* ___0_array, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mB806D1D0CA7A9E77FAF8539EA2D3ADD8E7F22743_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032_gshared (Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B* __this, Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405_gshared (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* ___0_array, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mD7B4B3E64408A7E514C24E9DCE9512D37C7531B3_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8_gshared (Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10* __this, Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D_gshared (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* ___0_array, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m45A4734AF06B5A7550F2C98081A3259A31F29645_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C_gshared (Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120* __this, Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03_gshared (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* ___0_array, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m18438DEE942A41F7A595B3E490E30F8E78044D1F_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t* ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD_gshared (Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247* __this, Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* ___0_q, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A_gshared (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* ___0_array, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_gshared_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_m89C5DC61DF69FB7B614F570A01A91F8D4555D74A_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_gshared_inline (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_gshared_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83_gshared (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56_gshared (uint32_t ___0_bitMap, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329_gshared (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3_gshared (NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, bool ___0_allocatedPage, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TreePage__ctor_m6DC52E242F1727514B983F48EF264E12E82574EB_gshared (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m4637CDAE893DECB44B1201D9DFEF3C18C0DB5257_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_mD851F770281DBDCB21B4DA2CB84909655F0FA687_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_mDB63445CC664F05D6EEF8AB921EE44CD858E8F45_gshared (uint32_t ___0_bitMap, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TreePage_AllocSlot_mEB4D7879BFA8750667B1902CA20FBF28279E1B52_gshared (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_userIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_m5B049EA2694E6343E2D30EDCDB34CC4C44A0FD08_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m63463D3F02F9E581B66DAC4F5311669F2284C603_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m7FD4570F1436DF16B372F9317522C5D1CDB8B597_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, RuntimeObject* ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45_gshared (NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mA462180E40EFE84991C0B4E4CA85D960D8655784_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m579F0FCDCC9A79BC70EEE156F07CC896029A410B_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_node, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_m55077BF0B4CAA5C5ABD5911CCB68C789D7652B4D_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_position, RuntimeObject* ___1_item, bool ___2_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_DeleteByIndex_m77EB3F96268C89DEA1218BA5DB3CB1A8EEC073F6_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_inline (const RuntimeMethod* method)
{
	return ((  RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* (*) (const RuntimeMethod*))Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85 (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, RuntimeObject* ___1_actualValue, String_t* ___2_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F (RuntimeArray* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, String_t* ___1_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC (RuntimeArray* __this, int32_t ___0_dimension, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57 (RuntimeArray* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
inline void Queue_1_SetCapacity_m3EE7DDC17C8BF4A848530E14BE83AB2FF51EAD72 (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m3EE7DDC17C8BF4A848530E14BE83AB2FF51EAD72_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4 (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132 (Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7* __this, Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7*, Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D*, const RuntimeMethod*))Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* ___0_array, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_inline (const RuntimeMethod* method)
{
	return ((  RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* (*) (const RuntimeMethod*))Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m06D7B5BE55FEF9235CFA3C383C4CD74A3DEC4792 (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m06D7B5BE55FEF9235CFA3C383C4CD74A3DEC4792_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17 (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8 (Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922* __this, Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922*, Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D*, const RuntimeMethod*))Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125 (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* ___0_array, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_inline (const RuntimeMethod* method)
{
	return ((  ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* (*) (const RuntimeMethod*))Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m7B994227375B3265506AD6D468B9FFBC4C1FC3BA (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m7B994227375B3265506AD6D468B9FFBC4C1FC3BA_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4 (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D (Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C* __this, Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C*, Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6*, const RuntimeMethod*))Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3 (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* ___0_array, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_inline (const RuntimeMethod* method)
{
	return ((  SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* (*) (const RuntimeMethod*))Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_mF2AC2CA3FB3A64549B30ABD823DAA8FF2D5FEC42 (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_mF2AC2CA3FB3A64549B30ABD823DAA8FF2D5FEC42_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8 (Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57* __this, Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57*, Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722*, const RuntimeMethod*))Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577 (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7 (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* ___0_array, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_inline (const RuntimeMethod* method)
{
	return ((  SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* (*) (const RuntimeMethod*))Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m9165403F0F0F7767662F23A1A6235E06D807D5CF (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m9165403F0F0F7767662F23A1A6235E06D807D5CF_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990 (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253 (Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920* __this, Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920*, Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03*, const RuntimeMethod*))Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304 (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629 (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* ___0_array, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_inline (const RuntimeMethod* method)
{
	return ((  SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* (*) (const RuntimeMethod*))Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m6B2C5C5826028020475F98EF83010A8CC0EF0594 (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m6B2C5C5826028020475F98EF83010A8CC0EF0594_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376 (Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696* __this, Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696*, Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC*, const RuntimeMethod*))Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192 (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246 (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* ___0_array, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_inline (const RuntimeMethod* method)
{
	return ((  TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* (*) (const RuntimeMethod*))Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_mB806D1D0CA7A9E77FAF8539EA2D3ADD8E7F22743 (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_mB806D1D0CA7A9E77FAF8539EA2D3ADD8E7F22743_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808 (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032 (Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B* __this, Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B*, Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE*, const RuntimeMethod*))Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90 (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405 (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* ___0_array, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_inline (const RuntimeMethod* method)
{
	return ((  TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* (*) (const RuntimeMethod*))Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_mD7B4B3E64408A7E514C24E9DCE9512D37C7531B3 (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_mD7B4B3E64408A7E514C24E9DCE9512D37C7531B3_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74 (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8 (Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10* __this, Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10*, Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F*, const RuntimeMethod*))Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6 (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* ___0_array, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_inline (const RuntimeMethod* method)
{
	return ((  TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* (*) (const RuntimeMethod*))Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m45A4734AF06B5A7550F2C98081A3259A31F29645 (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m45A4734AF06B5A7550F2C98081A3259A31F29645_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6 (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C (Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120* __this, Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120*, Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4*, const RuntimeMethod*))Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124 (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03 (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* ___0_array, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_inline (const RuntimeMethod* method)
{
	return ((  VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* (*) (const RuntimeMethod*))Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_gshared_inline)(method);
}
inline void Queue_1_SetCapacity_m18438DEE942A41F7A595B3E490E30F8E78044D1F (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB*, int32_t, const RuntimeMethod*))Queue_1_SetCapacity_m18438DEE942A41F7A595B3E490E30F8E78044D1F_gshared)(__this, ___0_capacity, method);
}
inline void Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0 (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t* ___0_index, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB*, int32_t*, const RuntimeMethod*))Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0_gshared)(__this, ___0_index, method);
}
inline void Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD (Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247* __this, Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* ___0_q, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247*, Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB*, const RuntimeMethod*))Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD_gshared)(__this, ___0_q, method);
}
inline void Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0 (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB*, const RuntimeMethod*))Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0_gshared)(__this, method);
}
inline int32_t Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* ___0_array, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, const RuntimeMethod*))RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t*, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751_gshared)(__this, ___0_index, ___1_satelliteRootId, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462 (int32_t ___0_internalError, const RuntimeMethod* method) ;
inline void RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA_gshared)(__this, ___0_tree, ___1_position, method);
}
inline void RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, const RuntimeMethod*))RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1 (const RuntimeMethod* method) ;
inline bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t*, int32_t*, const RuntimeMethod*))RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE_gshared)(__this, ___0_nodeId, ___1_mainTreeNodeId, method);
}
inline int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F_gshared)(__this, ___0_nodeId, method);
}
inline bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, const RuntimeMethod*))RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173_gshared)(__this, method);
}
inline int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, const RuntimeMethod*))RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_gshared_inline)(__this, method);
}
inline RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C_gshared)(__this, method);
}
inline void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4_gshared)(__this, method);
}
inline void RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700 (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, const RuntimeMethod*))RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t*, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007_gshared)(__this, ___0_index, ___1_satelliteRootId, method);
}
inline void RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D_gshared)(__this, ___0_tree, ___1_position, method);
}
inline void RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6 (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, const RuntimeMethod*))RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6_gshared)(__this, method);
}
inline bool RBTree_1_Successor_m89C5DC61DF69FB7B614F570A01A91F8D4555D74A (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t*, int32_t*, const RuntimeMethod*))RBTree_1_Successor_m89C5DC61DF69FB7B614F570A01A91F8D4555D74A_gshared)(__this, ___0_nodeId, ___1_mainTreeNodeId, method);
}
inline RuntimeObject* RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE_gshared)(__this, ___0_nodeId, method);
}
inline bool RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, const RuntimeMethod*))RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E_gshared)(__this, method);
}
inline RuntimeObject* RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_inline (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, const RuntimeMethod*))RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_gshared_inline)(__this, method);
}
inline RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A_gshared)(__this, method);
}
inline void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50 (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50_gshared)(__this, method);
}
inline void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_gshared)(__this, ___0_tree, method);
}
inline void RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C_gshared)(__this, ___0_tree, ___1_position, method);
}
inline void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955 (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_gshared)(__this, method);
}
inline bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_gshared)(__this, method);
}
inline void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, Il2CppFullySharedGenericAny*, const RuntimeMethod*))RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_gshared_inline)((RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*)__this, il2cppRetVal, method);
}
inline RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_gshared)(__this, method);
}
inline void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470 (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_gshared)(__this, method);
}
inline void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, const RuntimeMethod*))RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323_gshared)(__this, method);
}
inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	return ((  TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, int32_t, const RuntimeMethod*))TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_gshared_inline)(__this, ___0_value, method);
}
inline void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB_gshared)(__this, ___0_page, method);
}
inline int32_t TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_gshared_inline)(__this, method);
}
inline int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, bool, const RuntimeMethod*))RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA_gshared)(__this, ___0_allocatedPage, method);
}
inline void TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	((  void (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, int32_t, const RuntimeMethod*))TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, int32_t, const RuntimeMethod*))TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_gshared_inline)(__this, ___0_value, method);
}
inline int32_t TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_gshared_inline)(__this, method);
}
inline void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C_gshared)(__this, ___0_page, method);
}
inline int32_t RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56 (uint32_t ___0_bitMap, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint32_t, const RuntimeMethod*))RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56_gshared)(___0_bitMap, method);
}
inline int32_t TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, const RuntimeMethod*))TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45_gshared)(__this, ___0_nodeId, ___1_rightNodeId, method);
}
inline void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9_gshared)(__this, ___0_nodeId, ___1_parentNodeId, method);
}
inline void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8_gshared)(__this, ___0_nodeId, ___1_nextNodeId, method);
}
inline void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9_gshared)(__this, ___0_nodeId, ___1_key, method);
}
inline void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063_gshared)(__this, ___0_nodeId, ___1_leftNodeId, method);
}
inline int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55_gshared)(__this, ___0_nodeId, ___1_size, method);
}
inline void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNodeID, ___3_position, ___4_append, method);
}
inline int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568_gshared)(__this, ___0_key, method);
}
inline int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371_gshared)(__this, ___0_nodeId, ___1_color, method);
}
inline int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2_gshared)(__this, ___0_key, method);
}
inline NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method)
{
	return ((  NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8_gshared)(__this, ___0_userIndex, method);
}
inline int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC_gshared)(__this, ___0_root_id, ___1_z_id, ___2_mainTreeNodeID, method);
}
inline void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89_gshared)(__this, ___0_root_id, ___1_x_id, ___2_px_id, ___3_mainTreeNodeID, method);
}
inline void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2_gshared)(__this, ___0_root_id, ___1_key, method);
}
inline void NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3 (NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method)
{
	((  void (*) (NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50*, int32_t, int32_t, const RuntimeMethod*))NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3_gshared)(__this, ___0_nodeID, ___1_mainTreeNodeID, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Int32_Equals_m089564150E8AF7C63B419427E2E57E3420659B1B (int32_t* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
inline int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50, const RuntimeMethod*))RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5_gshared)(__this, ___0_path, method);
}
inline int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064_gshared)(__this, ___0_x_id, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054 (int32_t ___0_index, const RuntimeMethod* method) ;
inline int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297_gshared)(__this, ___0_node, method);
}
inline int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74_gshared)(__this, ___0_nodeId, ___1_item, method);
}
inline int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, int32_t, bool, const RuntimeMethod*))RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F_gshared)(__this, ___0_position, ___1_item, ___2_append, method);
}
inline int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, int32_t, const RuntimeMethod*))RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6_gshared)(__this, ___0_i, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8 (String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E (String_t* ___0_paramName, const RuntimeMethod* method) ;
inline int32_t RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, const RuntimeMethod*))RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8 (RuntimeArray* __this, RuntimeObject* ___0_value, int32_t ___1_index, const RuntimeMethod* method) ;
inline void RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, const RuntimeMethod*))RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781_gshared)(__this, method);
}
inline TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	return ((  TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, int32_t, const RuntimeMethod*))TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_gshared_inline)(__this, ___0_value, method);
}
inline void RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, const RuntimeMethod*))RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45_gshared)(__this, ___0_page, method);
}
inline int32_t TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, const RuntimeMethod*))TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_gshared_inline)(__this, method);
}
inline int32_t RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, bool ___0_allocatedPage, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, bool, const RuntimeMethod*))RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7_gshared)(__this, ___0_allocatedPage, method);
}
inline void TreePage__ctor_m6DC52E242F1727514B983F48EF264E12E82574EB (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, int32_t, const RuntimeMethod*))TreePage__ctor_m6DC52E242F1727514B983F48EF264E12E82574EB_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_PageId_m4637CDAE893DECB44B1201D9DFEF3C18C0DB5257_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, int32_t, const RuntimeMethod*))TreePage_set_PageId_m4637CDAE893DECB44B1201D9DFEF3C18C0DB5257_gshared_inline)(__this, ___0_value, method);
}
inline int32_t TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, const RuntimeMethod*))TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_gshared_inline)(__this, method);
}
inline void RBTree_1_FreePage_mD851F770281DBDCB21B4DA2CB84909655F0FA687 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, const RuntimeMethod*))RBTree_1_FreePage_mD851F770281DBDCB21B4DA2CB84909655F0FA687_gshared)(__this, ___0_page, method);
}
inline int32_t RBTree_1_GetIntValueFromBitMap_mDB63445CC664F05D6EEF8AB921EE44CD858E8F45 (uint32_t ___0_bitMap, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint32_t, const RuntimeMethod*))RBTree_1_GetIntValueFromBitMap_mDB63445CC664F05D6EEF8AB921EE44CD858E8F45_gshared)(___0_bitMap, method);
}
inline int32_t TreePage_AllocSlot_mEB4D7879BFA8750667B1902CA20FBF28279E1B52 (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, const RuntimeMethod*))TreePage_AllocSlot_mEB4D7879BFA8750667B1902CA20FBF28279E1B52_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4_gshared)(__this, ___0_nodeId, ___1_rightNodeId, method);
}
inline void RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493_gshared)(__this, ___0_nodeId, ___1_parentNodeId, method);
}
inline void RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8_gshared)(__this, ___0_nodeId, ___1_nextNodeId, method);
}
inline void RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_key, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, RuntimeObject*, const RuntimeMethod*))RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9_gshared)(__this, ___0_nodeId, ___1_key, method);
}
inline void RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052_gshared)(__this, ___0_nodeId, ___1_leftNodeId, method);
}
inline int32_t RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD_gshared)(__this, ___0_nodeId, ___1_size, method);
}
inline void RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNodeID, ___3_position, ___4_append, method);
}
inline int32_t RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, RuntimeObject*, const RuntimeMethod*))RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73_gshared)(__this, ___0_key, method);
}
inline int32_t RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2_gshared)(__this, ___0_nodeId, ___1_color, method);
}
inline int32_t RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline int32_t RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, RuntimeObject*, const RuntimeMethod*))RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA_gshared)(__this, ___0_key, method);
}
inline NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_userIndex, const RuntimeMethod* method)
{
	return ((  NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C_gshared)(__this, ___0_userIndex, method);
}
inline int32_t RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C_gshared)(__this, ___0_root_id, ___1_z_id, ___2_mainTreeNodeID, method);
}
inline void RBTree_1_RecomputeSize_m5B049EA2694E6343E2D30EDCDB34CC4C44A0FD08 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_RecomputeSize_m5B049EA2694E6343E2D30EDCDB34CC4C44A0FD08_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_DecreaseSize_m63463D3F02F9E581B66DAC4F5311669F2284C603 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_DecreaseSize_m63463D3F02F9E581B66DAC4F5311669F2284C603_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBDeleteFixup_m7FD4570F1436DF16B372F9317522C5D1CDB8B597 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteFixup_m7FD4570F1436DF16B372F9317522C5D1CDB8B597_gshared)(__this, ___0_root_id, ___1_x_id, ___2_px_id, ___3_mainTreeNodeID, method);
}
inline void RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, RuntimeObject* ___1_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, RuntimeObject*, const RuntimeMethod*))RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549_gshared)(__this, ___0_root_id, ___1_key, method);
}
inline void NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45 (NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method)
{
	((  void (*) (NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2*, int32_t, int32_t, const RuntimeMethod*))NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45_gshared)(__this, ___0_nodeID, ___1_mainTreeNodeID, method);
}
inline int32_t RBTree_1_GetIndexByNodePath_mA462180E40EFE84991C0B4E4CA85D960D8655784 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 ___0_path, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2, const RuntimeMethod*))RBTree_1_GetIndexByNodePath_mA462180E40EFE84991C0B4E4CA85D960D8655784_gshared)(__this, ___0_path, method);
}
inline int32_t RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5_gshared)(__this, ___0_x_id, ___1_index, method);
}
inline int32_t RBTree_1_GetIndexByNode_m579F0FCDCC9A79BC70EEE156F07CC896029A410B (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_node, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_GetIndexByNode_m579F0FCDCC9A79BC70EEE156F07CC896029A410B_gshared)(__this, ___0_node, method);
}
inline int32_t RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, RuntimeObject*, const RuntimeMethod*))RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E_gshared)(__this, ___0_nodeId, ___1_item, method);
}
inline int32_t RBTree_1_InsertAt_m55077BF0B4CAA5C5ABD5911CCB68C789D7652B4D (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_position, RuntimeObject* ___1_item, bool ___2_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, RuntimeObject*, bool, const RuntimeMethod*))RBTree_1_InsertAt_m55077BF0B4CAA5C5ABD5911CCB68C789D7652B4D_gshared)(__this, ___0_position, ___1_item, ___2_append, method);
}
inline RuntimeObject* RBTree_1_DeleteByIndex_m77EB3F96268C89DEA1218BA5DB3CB1A8EEC073F6 (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_i, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, int32_t, const RuntimeMethod*))RBTree_1_DeleteByIndex_m77EB3F96268C89DEA1218BA5DB3CB1A8EEC073F6_gshared)(__this, ___0_i, method);
}
inline int32_t RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669*, const RuntimeMethod*))RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B_gshared)(__this, method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mBE36D070D67CD7B9514992C2B957DEAD782B6C8B_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_0;
		L_0 = Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m65948375721A12D86C6F56148B849A8F4EAAEE41_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_6 = (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)(RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_mC3E2B8051D82EC556AFEA1E6C2202C13BABDC912_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_mBF597BDD200BCC7FAD457C5EDC4681FF20A16D85_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mFF4AA07B9C9CE42014D5F139A310CD541316AB10_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_mD786DF463E63A00E70EE43CAA71BE46BF983C099_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m093E57B581DFCC17AF65BE7652146489CEFD3402_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m928556A12AE98A583420CE11A9554CB1153245EA_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m3EE7DDC17C8BF4A848530E14BE83AB2FF51EAD72(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 Queue_1_GetEnumerator_mD79DB7C0CDE5101B1BAFFFF57D1B0C3B1F8BE2E1_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m0A00CA7BF2009459EA8BE4B498A4B22AD231DCB6_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_m4653B6D21170100856D9D0119505C3A56EA86D31_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m7B6EDAC6E45ED0FF0A0ED83628E74E50D2DF9132((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t3BC8EAF606B91138C671F4AEB3B2CAAF456197A7 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 Queue_1_Dequeue_mB3FA3D9093FFF08F098E6C1E2F81C3C9C8E0390F_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* V_1 = NULL;
	RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6));
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 Queue_1_Peek_m6D752408DB9E2AD07A0DD95213C12A3E3F15D334_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_mDA724C084BE62571F309D00C8B4180963A23EFBE_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6));
		return (bool)0;
	}

IL_0011:
	{
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6* L_2 = ___0_result;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_m0293A75465EE9C8B3B4DA93298C98427D31EF334_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = __this->____array;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_8 = __this->____array;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_14 = __this->____array;
		RotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_m7939EBB7DE3B0C099EB503FF50D00ABA18CD475D(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* Queue_1_ToArray_m2C0536E0AC24B727C947EE41A2D63658014CA5EA_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_1;
		L_1 = Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)(RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_12 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_15 = __this->____array;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_16 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m3EE7DDC17C8BF4A848530E14BE83AB2FF51EAD72_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* V_0 = NULL;
	Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* G_B6_0 = NULL;
	Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_1 = (RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)(RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_11 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_14 = __this->____array;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_15 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m52BF4F216585A90D38D3C6B9FA208D7962CDE4B4_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m0EBE213721CBC0DB5DDC03F4E5F8E6465BB4193F_gshared (Queue_1_t9FA265C8E0E8BDEBE8DBED5C7F4E420B7C3ED03D* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m67BD666D30B34E12A43214BEE10AC7FEEB7FC8A0_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_0;
		L_0 = Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m871E22D7551923F4CD9966C1530D1503148F42ED_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_6 = (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)(RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m5F448492859EB5D9C0FB034E94E4E42573AE4289_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_m43ED8AE4BFFF0CDE605B3700947F4BEEC2B13C9E_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mE0B934FBE3D6B63415C431224CE979B179530D6F_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m094160AC6368ED0BC968F0D713A45B0D183E7017_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_mB1AABB779E92B9FC5B961F3B3FFFD268EB6D4538_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_mFA3C0A1B0CFB80EDEE57203C5C536B16C7262875_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m06D7B5BE55FEF9235CFA3C383C4CD74A3DEC4792(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 Queue_1_GetEnumerator_m14A3B664C17884EEF5DF1A231854E111A269381B_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mCAAF127F1EC368B2BC837E0A9899543BE3E7BBF1_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_mF4F8C857DEF800B97E65A910FC48BE534EECC627_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF692387BB4116F7998F307A7FFAD03C96E5F47D8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tE86A0C1F3FA0726AEC68EDEA1B95782056A41922 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 Queue_1_Dequeue_m300E36534089E0B56908030B58141AF27EC2E456_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* V_1 = NULL;
	RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6));
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 Queue_1_Peek_m253955779486759CBEE674C3DC67EE39C1D29F59_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m3200CF41FE2132AFC394F0DFE64ED011AC1E4956_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6));
		return (bool)0;
	}

IL_0011:
	{
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6* L_2 = ___0_result;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_m3295B56886E41D3827EB43511B4D7B5C3CC47DA3_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = __this->____array;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_8 = __this->____array;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_14 = __this->____array;
		RotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m75EF676D3359D585190A984449A0942807867EEE(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* Queue_1_ToArray_m617B4D65C8F80A6D59B665E9F6298133474A0EAC_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_1;
		L_1 = Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)(RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_12 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_15 = __this->____array;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_16 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m06D7B5BE55FEF9235CFA3C383C4CD74A3DEC4792_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* V_0 = NULL;
	Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* G_B6_0 = NULL;
	Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_1 = (RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)(RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_11 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_14 = __this->____array;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_15 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m9AB4859605F51D7FFC3E732BD78F12ED623A6F17_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mD77DAE9F8E6C99BD4E01B159FA8D36D8B9AAF125_gshared (Queue_1_tBF1D02B07565C1EAA28556CFDAA2E3555501F50D* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m985D7F9BB4DA03D0E0C0842231138379B726E19A_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_0;
		L_0 = Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m1D031B44FCBFEF5AFA79067D932D89177E224895_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_6 = (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)(ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m40638BDBD7E5CE07B02BB78087027D57F2AFAAAB_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_mF4C99EDA4BA50B83FEED1BC2F2A09DAB79F2A02F_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mB552780933DFCFBC1433CF3BA9940750FC17D08A_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m3ECA7E3D9C46B139970BD18D1F321B40C261C934_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m414BB538BDD1B3F8A40FED4AEE9A52FF1E138641_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m58492A4F5805C149FD8357FB0D82BC6017F50153_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m7B994227375B3265506AD6D468B9FFBC4C1FC3BA(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C Queue_1_GetEnumerator_mE03FFDD66DB55E2A56813C3F61950D802F5D8B77_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mEBEC8C060089FC29FC273D810E7E30999C90F9DC_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_m0B7A115A752F70926F570463FB786F665F2D4758_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF75902196303BAF176D98D9E2CC8C790066AA36D((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t28136747FD61ACF924C71B74CE5CB33F5FDE221C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 Queue_1_Dequeue_mDEEF60E14D32343822219FEA48630711D79CE0A1_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* V_1 = NULL;
	ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 V_2;
	memset((&V_2), 0, sizeof(V_2));
	ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2));
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 Queue_1_Peek_mC14F031778647FF2C866DD8B623549A2089CAD78_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_mD8462CD42C8215E9F3D6364E74D822284C8D4B7E_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2));
		return (bool)0;
	}

IL_0011:
	{
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2* L_2 = ___0_result;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_m8D68B1228BB75BBFF1C5BB18E9C927BE1B8B1AE2_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = __this->____array;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_8 = __this->____array;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_14 = __this->____array;
		ShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_mCBB72766D2493E76B21CC02D5FE5F58542FC7DBE(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* Queue_1_ToArray_m9C936007DB93B96D543D5200CF35C0E63E1799EB_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_1;
		L_1 = Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)(ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_12 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_15 = __this->____array;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_16 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m7B994227375B3265506AD6D468B9FFBC4C1FC3BA_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* V_0 = NULL;
	Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* G_B6_0 = NULL;
	Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_1 = (ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)(ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_11 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_14 = __this->____array;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_15 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mAD088977D1BFE3B3B419965739E95586C2CBF1D4_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mAEBA69695B2B981467316821D5F68FC9793F22E3_gshared (Queue_1_tB5C7771CD791E4C5A79218CD2C607517B63C00F6* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m54FDEF30D4AA4D9473F033F678961DE454866EA2_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_0;
		L_0 = Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mA9A17E607CAA55466E8E46ED4E8D7E62A7A11EBD_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_6 = (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)(SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_mF0A7FC81177726AA6440024EC44C079A4263F007_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_m9F6B599967E9ED0936A59C9739462CC925E5BADB_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mD46079CB05CFD8FB2B7E3F6896206310045E7DE0_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_mAB9086CEDC5F3E4BC550529EDD32CCE551B34D96_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m5F4F7B4234716597ABAED2503D5C043B2E8AFECA_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_mFE1CE339A6D9334B4BBFB750F1BBDAA69F6CCE97_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_mF2AC2CA3FB3A64549B30ABD823DAA8FF2D5FEC42(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 Queue_1_GetEnumerator_mCBD3924C298BCF0DB68F8647FFD21DC9BDDCB698_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3EF9BAE632340C95A5DD773AF03E1533271796B8_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_mE11C41F4DFC8D47DA6037D792DAE53D611CBD774_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m47741F5A74E3B398EF05B1851CB6FAA53A54EBB8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBC8B7CC2DAC33A9808E0B9D802C51843715F8B57 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 Queue_1_Dequeue_m9E8BFF3C97B2326780FD96250DC7705D6A48C95C_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* V_1 = NULL;
	SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 V_2;
	memset((&V_2), 0, sizeof(V_2));
	SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4));
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 Queue_1_Peek_m77050696DEA3DABF0D9A271A08EBF18A90B5E218_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m683AE2B45C6EFDE0BFF66FBBAB457377FBDB35EE_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4));
		return (bool)0;
	}

IL_0011:
	{
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4* L_2 = ___0_result;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_mDC21B07446EB448161262E93F4D459C21A328899_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = __this->____array;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_8 = __this->____array;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_14 = __this->____array;
		SizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m23F413049BC2FC1CD67C3464478B023258EBA3F7(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* Queue_1_ToArray_mD708B781EB16B15C9536703AB5825505C2AB7BD3_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_1;
		L_1 = Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)(SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_12 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_15 = __this->____array;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_16 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mF2AC2CA3FB3A64549B30ABD823DAA8FF2D5FEC42_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* V_0 = NULL;
	Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* G_B6_0 = NULL;
	Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_1 = (SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)(SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_11 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_14 = __this->____array;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_15 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m2B2042DA5BCAADE90BD07D423F1EFDBB886709BC_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m39E173CC1E5FD7AF2C7907CD7CF099DB4CCCB577_gshared (Queue_1_tABEA5C7CAAB3B865D2F50F23AFA9C9D95DC83722* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m15F96D2F85490E73D916057CA891CC3F6FADA533_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_0;
		L_0 = Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mF794855E43E16FD17672CDF690762592002FA191_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_6 = (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)(SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m647346BA228E0A930FC92D054A74B6CDD4BA3845_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_mE7C0F17AF0CD506E6FD84F554E4EFC24CB1F53B7_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_m9662B2969176B9AC233880481A71B24852374D53_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m837254C7B1BD3A07CF40125B46A53125E442E64A_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m5EE47D56859EFE4495676568F360F3356BEDBEDD_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_mFF443B647939DD13F5E5D64DAC9C462A98886F40_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m9165403F0F0F7767662F23A1A6235E06D807D5CF(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 Queue_1_GetEnumerator_m297B6AA1DBA254A14E60D66C8CC48BC1F5F0CFDA_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mFB45EAFBE264E3B010C46274B03B5620A04618A4_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_mF6DF1CF61836F6111A931D3FA1087667CFF40102_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mE8EEF8C22FFFEF87157D2F38BC4B159A53642253((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBDEE937DC978007344F2C66A05E9710AB09A2920 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C Queue_1_Dequeue_m6EA82707456AB309708639323071E0DAEB1A5B0C_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* V_1 = NULL;
	SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C V_2;
	memset((&V_2), 0, sizeof(V_2));
	SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C));
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C Queue_1_Peek_m11DBB04669C9B10892F0A851DF88989399969C63_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m9E7EA790DB8C6699E05BEA0A14778FE21FC94883_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C));
		return (bool)0;
	}

IL_0011:
	{
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C* L_2 = ___0_result;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_m0CF5478BE3324D9EE0A1AB1CC77A70300BD39399_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = __this->____array;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_8 = __this->____array;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_14 = __this->____array;
		SizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m5F67D0DB2FCA0D12584A747E67BF02700BC34629(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* Queue_1_ToArray_mDEAD4F7E738F4E93C3025CC33DDAD96FD17D2966_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_1;
		L_1 = Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)(SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_12 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_15 = __this->____array;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_16 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m9165403F0F0F7767662F23A1A6235E06D807D5CF_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* V_0 = NULL;
	Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* G_B6_0 = NULL;
	Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_1 = (SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)(SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_11 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_14 = __this->____array;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_15 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mE0C43CFEDDCD3B1D18F295FCE3F00C8C3595A990_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m16D5601251C9383B03A20BE5B267E9AC2CC6A304_gshared (Queue_1_t9F5EC60BA20905CF85F0EC6D5CF8CDBA2DDEBF03* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m709CB1CD1F793D44AF329E2235CE5452B8008A21_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_0;
		L_0 = Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mB21813C25DFAA14D9CBCF4F6CD43CCA69C36C06E_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_6 = (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)(SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_mAC9233AA31DA8151234EEF8A52C05B390B93CB3C_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_m69438EC10E4ABA04B76B296EAA112863C78C66FD_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_m3B7E4A3758D6B511F4DC75547024A1027EE80672_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m20AA94ADA3F4FC2E625AE1BD11E27E913B502A7B_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m3233C284708BFFD1DF0749763D4EEA5920973BB6_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m8771A1C4CFCEDFD8E8551262A52B8A4F85937029_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m6B2C5C5826028020475F98EF83010A8CC0EF0594(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 Queue_1_GetEnumerator_m97A1862FDC53ED835E6C7A3656DD72307E16E6F1_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mE0C3DFF036CFAFC447EA79DBDCDE62647E8A14DE_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_m0518B641E160F0D248F188F7E802B0E47D839F70_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mDB06CA75CE220B7F13D93F64A0AC031FE16E1376((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tC101FE0399B2E5BB3E7512B286064A26F42F6696 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B Queue_1_Dequeue_mB55AC7AC44ED1698C5D06C655D8F65013597132D_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* V_1 = NULL;
	SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B V_2;
	memset((&V_2), 0, sizeof(V_2));
	SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B));
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B Queue_1_Peek_m9227A3C6CA723F9CA5FF243832E10E68B1D9E337_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m5C91D185B14E85E95DC89299DC52D13F35499C08_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B));
		return (bool)0;
	}

IL_0011:
	{
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B* L_2 = ___0_result;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_mC9E0D389155789105DA103C78E58BAF36787740A_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = __this->____array;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_8 = __this->____array;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_14 = __this->____array;
		SubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m0BC657C2665F4257A5FB5B35E92728C0F0533246(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* Queue_1_ToArray_m345DB4A36A2B8F3E1A62329962969976DD811F0B_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_1;
		L_1 = Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)(SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_12 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_15 = __this->____array;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_16 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m6B2C5C5826028020475F98EF83010A8CC0EF0594_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* V_0 = NULL;
	Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* G_B6_0 = NULL;
	Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_1 = (SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)(SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_11 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_14 = __this->____array;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_15 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mA7612B3642C784E094FEA6B2020E32C4953D8BEF_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m762921511DDCF44E074EB355C146B5ACEE6E9192_gshared (Queue_1_t729B9C657F6A9ECE0085BB5615128913418843BC* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m02B1D9EFFAF9F343EEC9BC071E2A07B5BCA16203_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_0;
		L_0 = Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m18070F8C2B62B51B13ACB169B15EAE7D0A97C410_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_6 = (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)(TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_mB2D96E2ECFEA56FF24FBFD5FF3FCFDEB268D616D_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_mD9CA1FD2869D3DEFCE0F48A5B2D6D585E23A5D4F_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_m6F72171C3095A017E2F3235C3DC852FF65F5D005_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_mE3326987417F6D30D54A4FD4D7F9A89150C09B74_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_mC662B98A2AFAF19F9F853B34076F3AD4EC278EE2_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m5F6F4A967639713EF85BE64D3B7551194DF2AA8B_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_mB806D1D0CA7A9E77FAF8539EA2D3ADD8E7F22743(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B Queue_1_GetEnumerator_m5AB77E70DC6FB15ABCDDE271509816D64670A925_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mA40E7173A281017B0D71CA860CC3AC87B7B45EB8_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_m77C07337ADF720916E7C767B88716BB5051351F9_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m8F53179CC3E75795C3E09AA9195A15979EA6D032((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t2795FFE0C3F3E79588F5008040A26AF12C90508B L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 Queue_1_Dequeue_m735F838C0D960F38B50E05160FF5C60C5425E0B1_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* V_1 = NULL;
	TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6));
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 Queue_1_Peek_m6AF8EFC0FB6E3C5E5B21395124AD5EA6971ED31D_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_mC4BEE36A759BFFD865EB162E832B814A844B59AD_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6));
		return (bool)0;
	}

IL_0011:
	{
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6* L_2 = ___0_result;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_m6BE83C116BC2703E13D44BBF23B476D1EE9783A6_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = __this->____array;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_8 = __this->____array;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_14 = __this->____array;
		TextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m1F335E805AA3EB5B81C747C829F248A1A2C90405(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* Queue_1_ToArray_m42A9EE3B0B4D2E8DB5A5D8B937B129E73DEED319_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_1;
		L_1 = Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)(TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_12 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_15 = __this->____array;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_16 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mB806D1D0CA7A9E77FAF8539EA2D3ADD8E7F22743_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* V_0 = NULL;
	Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* G_B6_0 = NULL;
	Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_1 = (TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)(TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_11 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_14 = __this->____array;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_15 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m090ABB3B0EB4A5CE06372DC4621A2BE4B3EF3808_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m660DA5A506043FDB9E960385F49A81427A238A90_gshared (Queue_1_t1056FBEDA0F04A7B5EB41B05FBD7FEB8FBD71DFE* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mC45B96F088ECC767415437970B0EE035CADA04A0_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_0;
		L_0 = Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mBEFFC8870B0E1C79B9532CB6670C1C31DA21E72E_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_6 = (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)(TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_mE6C78D483FA0C5AFFB6091E09C0C5687362A4449_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_m0F96CBAD9B9E356EF2E6DFB962D02A0DAFC8CDF4_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mE733C6BA245BEB83538FBBC328DA9C78FDE053B7_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m551E246FC8C8DBCA08155FA0A4F0B414160A4AA2_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_mA8846F96638EADA774FCA20F308EDD7A9A4512FB_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m4583DEBE063301BAB194498A03C6135543BED616_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_mD7B4B3E64408A7E514C24E9DCE9512D37C7531B3(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 Queue_1_GetEnumerator_m3FD28AF847E014B6E4257FCD6F83B464C0B0A731_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m9B5350E69E1307210B140C63C28D8857D8B20B24_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_m95B08E808187A7C0BD8A347C93AA9861B27BDE0E_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m41A07AA80A993CA6A9D260518BF4B73B75092EF8((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_t3E9746E7B55D709B79A878C742C8E575F4FA9F10 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D Queue_1_Dequeue_m4A7BBC06D6C6E504EF41E5F5D8F2054A5ED7AF72_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* V_1 = NULL;
	TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D V_2;
	memset((&V_2), 0, sizeof(V_2));
	TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D));
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D Queue_1_Peek_m86C6EC3B5FBA23BD635ACA773A3F755B17EF53ED_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m35F5D27159DFE93CAB1E8038CD4111472FED1A3C_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D));
		return (bool)0;
	}

IL_0011:
	{
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D* L_2 = ___0_result;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_mB11F6BDE7C8CFBD028B0320C75C59B0D7357CB87_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = __this->____array;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_8 = __this->____array;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_14 = __this->____array;
		TrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m4BC4E9A50ADB49F13DD33E9CB4220EB2B787BC0D(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* Queue_1_ToArray_mFD5475D18244A06BA764F0FE0060985A71A40BE4_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_1;
		L_1 = Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)(TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_12 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_15 = __this->____array;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_16 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_mD7B4B3E64408A7E514C24E9DCE9512D37C7531B3_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* V_0 = NULL;
	Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* G_B6_0 = NULL;
	Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_1 = (TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)(TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_11 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_14 = __this->____array;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_15 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_m8C5624B80E8A9CFD986CA30F3258432D4126AA74_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_m31D33C41A808198FFC229314EDF863BDEAC148F6_gshared (Queue_1_tC5A9DCFA8100FB31BFC33E2FF9801ECE71F4482F* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m441C064C78B457952CE1BB105B7D3D954D9C24FD_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_0;
		L_0 = Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mE8695227CEF0E5BA52B1FE21EF78B386E61A8B99_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_6 = (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)(TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m27DE0E6B051B459F9610EF5C2A98BD41121BA49E_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_mF143EB9784FA446FC698811E2DC63ACCAEB17713_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_m97FA8B14F2BE86B72BC2F68C9809D442DC38C456_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_mC9318699EBE278BA3FBDCFE814DFC9DFAE9D7E58_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m5495000C19CCE753BFB25A99AC8DF59CF69D4F69_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m9614909EB6770CD77F444903C68742C8CC555BD5_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m45A4734AF06B5A7550F2C98081A3259A31F29645(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 Queue_1_GetEnumerator_m2DCAD7BD0A81F3C10835231D0EF143D254FEDF95_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mDFFB7C5C9FD8CFA194827715C40FAC101DEA0964_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_mC29F08BB8301165EB3224E379B64C0FEB61B669F_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4A23A9F879C00B45C48869F8F4C0B8D4C7201D1C((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBDD2A6BCB856249222E044E3A8E0DC7845488120 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 Queue_1_Dequeue_m25C60E585A4E7A3C61BBD34610F1234AB73D3489_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* V_1 = NULL;
	TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 V_2;
	memset((&V_2), 0, sizeof(V_2));
	TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1));
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 Queue_1_Peek_m699ECBC896BDE06A526B19A997810D953A7FBE27_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_m515E36E0C1C7686E83965587B8B3FD80D54DDF7D_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1));
		return (bool)0;
	}

IL_0011:
	{
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1* L_2 = ___0_result;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_mEA19D46EA69EDAA011D36D44F47D0F0E86E89B0B_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = __this->____array;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_8 = __this->____array;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_14 = __this->____array;
		TriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_mC8E8CB3BBB2BDC7AB9B76EEDC16C180815528E03(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* Queue_1_ToArray_m2D5AEDC38E76FE08B72BC1153899AC3B10B6AC89_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_1;
		L_1 = Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)(TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_12 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_15 = __this->____array;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_16 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m45A4734AF06B5A7550F2C98081A3259A31F29645_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* V_0 = NULL;
	Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* G_B6_0 = NULL;
	Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_1 = (TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)(TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_11 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_14 = __this->____array;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_15 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mD78DEEA1B5ECF46D998D4FB897615BAECA14A2F6_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mA4737D0CCF8E091CF65316859935209FB8F52124_gshared (Queue_1_t801ED8B4E9F14DFDBC6B112D1F06F96345AD90F4* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 11518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_m31BD024CE7CE1BCED3E56C0D40EE78765E121EAD_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_0;
		L_0 = Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__this->____array = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_0);
		return;
	}
}
// Method Definition Index: 11519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mCA3B3B75F36224FB7783EFBC34888398B6207FEF_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0020;
		}
	}
	{
		int32_t L_1 = ___0_capacity;
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_defaults.int32_class, &L_2);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC37D78082ACFC8DEE7B32D9351C6E433A074FEC7)), L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral38E3DBC7FC353425EF3A98DC8DAC6689AF5FD1BE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0020:
	{
		int32_t L_5 = ___0_capacity;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_6 = (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)(VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_5);
		__this->____array = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_6);
		return;
	}
}
// Method Definition Index: 11520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m09427CAEF442DF1E4FE00FF8BE2A429AF799A26D_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_System_Collections_ICollection_get_IsSynchronized_m7C280ED6F93FCF590C924C48391901154CEBF38B_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
// Method Definition Index: 11522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_ICollection_get_SyncRoot_mFD1EC3006D171CC68CDBEA915D1E00B816080E1F_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = InterlockedCompareExchangeImpl<RuntimeObject*>(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
// Method Definition Index: 11523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m332B5D6863D5AB53F6B6C985D4B0965EED1CC891_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_006f;
		}
	}
	{
	}
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0036;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____size;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, L_4, L_5, NULL);
		goto IL_0068;
	}

IL_0036:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_8 = __this->____array;
		NullCheck(L_8);
		int32_t L_9 = __this->____head;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_6, L_7, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_8)->max_length)), L_9)), NULL);
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_10 = __this->____array;
		int32_t L_11 = __this->____tail;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0068:
	{
		__this->____size = 0;
	}

IL_006f:
	{
		__this->____head = 0;
		__this->____tail = 0;
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_System_Collections_ICollection_CopyTo_m8EC3EC78F7028F1C90D74ED20A20C5C854C1515B_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B17_0 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		RuntimeArray* L_2 = ___0_array;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Array_get_Rank_m9383A200A2ECC89ECA44FE5F812ECFB874449C5F(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0027;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_4 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral967D403A541A1026A83D548E5AD5CA800AD4EFB5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, method);
	}

IL_0027:
	{
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_5, 0, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6195D7DA68D16D4985AD1A1B4FD2841A43CDDE70)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0040:
	{
		RuntimeArray* L_8 = ___0_array;
		NullCheck(L_8);
		int32_t L_9;
		L_9 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_8, NULL);
		V_0 = L_9;
		int32_t L_10 = ___1_index;
		if ((((int32_t)L_10) < ((int32_t)0)))
		{
			goto IL_004f;
		}
	}
	{
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) <= ((int32_t)L_12)))
		{
			goto IL_0065;
		}
	}

IL_004f:
	{
		int32_t L_13 = ___1_index;
		int32_t L_14 = L_13;
		RuntimeObject* L_15 = Box(il2cpp_defaults.int32_class, &L_14);
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_16 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_m60B543A63AC8692C28096003FBF2AD124B9D5B85(L_16, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), L_15, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral569FEAE6AEE421BCD8D24F22865E84F808C2A1E4)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_0065:
	{
		int32_t L_17 = V_0;
		int32_t L_18 = ___1_index;
		int32_t L_19 = __this->____size;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_17, L_18))) >= ((int32_t)L_19)))
		{
			goto IL_007b;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_20 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7F4C724BD10943E8B0B17A6E069F992E219EF5E8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_007b:
	{
		int32_t L_21 = __this->____size;
		V_1 = L_21;
		int32_t L_22 = V_1;
		if (L_22)
		{
			goto IL_0086;
		}
	}
	{
		return;
	}

IL_0086:
	{
	}
	try
	{
		{
			VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_23 = __this->____array;
			NullCheck(L_23);
			int32_t L_24 = __this->____head;
			int32_t L_25 = V_1;
			if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_23)->max_length)), L_24))) < ((int32_t)L_25)))
			{
				goto IL_009c_1;
			}
		}
		{
			int32_t L_26 = V_1;
			G_B17_0 = L_26;
			goto IL_00ab_1;
		}

IL_009c_1:
		{
			VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_27 = __this->____array;
			NullCheck(L_27);
			int32_t L_28 = __this->____head;
			G_B17_0 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_27)->max_length)), L_28));
		}

IL_00ab_1:
		{
			V_2 = G_B17_0;
			VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_29 = __this->____array;
			int32_t L_30 = __this->____head;
			RuntimeArray* L_31 = ___0_array;
			int32_t L_32 = ___1_index;
			int32_t L_33 = V_2;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_29, L_30, L_31, L_32, L_33, NULL);
			int32_t L_34 = V_1;
			int32_t L_35 = V_2;
			V_1 = ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
			int32_t L_36 = V_1;
			if ((((int32_t)L_36) <= ((int32_t)0)))
			{
				goto IL_00e7_1;
			}
		}
		{
			VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_37 = __this->____array;
			RuntimeArray* L_38 = ___0_array;
			int32_t L_39 = ___1_index;
			VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_40 = __this->____array;
			NullCheck(L_40);
			int32_t L_41 = __this->____head;
			int32_t L_42 = V_1;
			Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_37, 0, L_38, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_39, ((int32_t)(((RuntimeArray*)L_40)->max_length)))), L_41)), L_42, NULL);
		}

IL_00e7_1:
		{
			goto IL_00fa;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00e9;
		}
		throw e;
	}

CATCH_00e9:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_43 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_44 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_44, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBD0381A992FDF4F7DA60E5D83689FE7FF6309CB8)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_44, method);
	}

IL_00fa:
	{
		return;
	}
}
// Method Definition Index: 11525
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m99CDD92E9DC739CE4E67E52E841612F4BB6BBB4A_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_1 = __this->____array;
		NullCheck(L_1);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))))))
		{
			goto IL_0045;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_2 = __this->____array;
		NullCheck(L_2);
		V_0 = ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)((int32_t)(((RuntimeArray*)L_2)->max_length))), ((int64_t)((int32_t)200))))/((int64_t)((int32_t)100)))));
		int32_t L_3 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_4 = __this->____array;
		NullCheck(L_4);
		if ((((int32_t)L_3) >= ((int32_t)((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_4)->max_length)), 4)))))
		{
			goto IL_003e;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_5 = __this->____array;
		NullCheck(L_5);
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_5)->max_length)), 4));
	}

IL_003e:
	{
		int32_t L_6 = V_0;
		Queue_1_SetCapacity_m18438DEE942A41F7A595B3E490E30F8E78044D1F(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
	}

IL_0045:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_7 = __this->____array;
		int32_t L_8 = __this->____tail;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56)L_9);
		int32_t* L_10 = (int32_t*)(&__this->____tail);
		Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return;
	}
}
// Method Definition Index: 11526
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 Queue_1_GetEnumerator_mEAC55CF0E9241D5597954EC7967BCB9D2F1B61DF_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return L_0;
	}
}
// Method Definition Index: 11527
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mE9312ABFCFA98E75756B5F532D4F52603F589822_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11528
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Queue_1_System_Collections_IEnumerable_GetEnumerator_mA2626D78EB41551F256BC67132515320D2E5DC58_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m6C013C3931125150D41207B11524C00688E023DD((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		Enumerator_tBBFD44A44EA8094BEF5A0D1E86E51EECCD06F247 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 11529
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 Queue_1_Dequeue_m88B18BF278F089C05437EF2B4C0AC05A19A5402E_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* V_1 = NULL;
	VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 V_2;
	memset((&V_2), 0, sizeof(V_2));
	VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 G_B4_0;
	memset((&G_B4_0), 0, sizeof(G_B4_0));
	VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		int32_t L_0 = __this->____head;
		V_0 = L_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_1 = __this->____array;
		V_1 = L_1;
		int32_t L_2 = __this->____size;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_001c:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = V_1;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		G_B3_0 = L_6;
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_7 = V_1;
		int32_t L_8 = V_0;
		il2cpp_codegen_initobj((&V_2), sizeof(VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56));
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_9 = V_2;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56)L_9);
		G_B4_0 = G_B3_0;
	}

IL_003a:
	{
		int32_t* L_10 = (int32_t*)(&__this->____head);
		Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		int32_t L_11 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_11, 1));
		int32_t L_12 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_12, 1));
		return G_B4_0;
	}
}
// Method Definition Index: 11530
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 Queue_1_Peek_m64CD81A396F977E6704B3833DE4BC87F7974A3C8_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
	}

IL_000e:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_1 = __this->____array;
		int32_t L_2 = __this->____head;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		return L_4;
	}
}
// Method Definition Index: 11531
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_TryPeek_mFB59909BA91B31CD0B81E4B9E79DDA7C29CE6644_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56* ___0_result, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56* L_1 = ___0_result;
		il2cpp_codegen_initobj(L_1, sizeof(VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56));
		return (bool)0;
	}

IL_0011:
	{
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56* L_2 = ___0_result;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = __this->____array;
		int32_t L_4 = __this->____head;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		*(VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56*)L_2 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56*)L_2)->___m_ParticleSystem), (void*)NULL);
		return (bool)1;
	}
}
// Method Definition Index: 11532
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Queue_1_Contains_mBB88791CBC70470C8637CFD9C63139002FA8EA84_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		int32_t L_1 = __this->____head;
		int32_t L_2 = __this->____tail;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_0037;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = __this->____array;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_4 = ___0_item;
		int32_t L_5 = __this->____head;
		int32_t L_6 = __this->____size;
		int32_t L_7;
		L_7 = Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A(L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_7) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0037:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_8 = __this->____array;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_9 = ___0_item;
		int32_t L_10 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_11 = __this->____array;
		NullCheck(L_11);
		int32_t L_12 = __this->____head;
		int32_t L_13;
		L_13 = Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A(L_8, L_9, L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_11)->max_length)), L_12)), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if ((((int32_t)L_13) >= ((int32_t)0)))
		{
			goto IL_0075;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_14 = __this->____array;
		VelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56 L_15 = ___0_item;
		int32_t L_16 = __this->____tail;
		int32_t L_17;
		L_17 = Array_IndexOf_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_mD0FBEA5B829CE6CB0A117E63C6819043C0BEA89A(L_14, L_15, 0, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		return (bool)((((int32_t)((((int32_t)L_17) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		return (bool)1;
	}
}
// Method Definition Index: 11533
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* Queue_1_ToArray_m1AEDCD2BABE3FA7E7466E5A91777E57932F7333C_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_1;
		L_1 = Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_inline(il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)(VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_2);
		V_0 = L_3;
		int32_t L_4 = __this->____head;
		int32_t L_5 = __this->____tail;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_0043;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_6 = __this->____array;
		int32_t L_7 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_8 = V_0;
		int32_t L_9 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, 0, L_9, NULL);
		goto IL_0087;
	}

IL_0043:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_10 = __this->____array;
		int32_t L_11 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_12 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_13 = __this->____array;
		NullCheck(L_13);
		int32_t L_14 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, L_11, (RuntimeArray*)L_12, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_13)->max_length)), L_14)), NULL);
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_15 = __this->____array;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_16 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_17 = __this->____array;
		NullCheck(L_17);
		int32_t L_18 = __this->____head;
		int32_t L_19 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_15, 0, (RuntimeArray*)L_16, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_17)->max_length)), L_18)), L_19, NULL);
	}

IL_0087:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 11534
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_SetCapacity_m18438DEE942A41F7A595B3E490E30F8E78044D1F_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* V_0 = NULL;
	Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* G_B6_0 = NULL;
	Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* G_B5_0 = NULL;
	int32_t G_B7_0 = 0;
	Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* G_B7_1 = NULL;
	{
		int32_t L_0 = ___0_capacity;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_1 = (VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)(VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 3), (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_3 = __this->____head;
		int32_t L_4 = __this->____tail;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0039;
		}
	}
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_5 = __this->____array;
		int32_t L_6 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_7 = V_0;
		int32_t L_8 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, L_6, (RuntimeArray*)L_7, 0, L_8, NULL);
		goto IL_007d;
	}

IL_0039:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_9 = __this->____array;
		int32_t L_10 = __this->____head;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_11 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_12 = __this->____array;
		NullCheck(L_12);
		int32_t L_13 = __this->____head;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, L_10, (RuntimeArray*)L_11, 0, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_12)->max_length)), L_13)), NULL);
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_14 = __this->____array;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_15 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_16 = __this->____array;
		NullCheck(L_16);
		int32_t L_17 = __this->____head;
		int32_t L_18 = __this->____tail;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_16)->max_length)), L_17)), L_18, NULL);
	}

IL_007d:
	{
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_19 = V_0;
		__this->____array = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____array), (void*)L_19);
		__this->____head = 0;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___0_capacity;
		if ((((int32_t)L_20) == ((int32_t)L_21)))
		{
			G_B6_0 = __this;
			goto IL_009d;
		}
		G_B5_0 = __this;
	}
	{
		int32_t L_22 = __this->____size;
		G_B7_0 = L_22;
		G_B7_1 = G_B5_0;
		goto IL_009e;
	}

IL_009d:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
	}

IL_009e:
	{
		NullCheck(G_B7_1);
		G_B7_1->____tail = G_B7_0;
		int32_t L_23 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_23, 1));
		return;
	}
}
// Method Definition Index: 11535
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_MoveNext_mC8351EFE844A4FC42174A43F1F414886ADC05EE0_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, int32_t* ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t* L_0 = ___0_index;
		int32_t L_1 = *((int32_t*)L_0);
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		int32_t L_2 = V_0;
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_3 = __this->____array;
		NullCheck(L_3);
		if ((!(((uint32_t)L_2) == ((uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length))))))
		{
			goto IL_0012;
		}
	}
	{
		V_0 = 0;
	}

IL_0012:
	{
		int32_t* L_4 = ___0_index;
		int32_t L_5 = V_0;
		*((int32_t*)L_4) = (int32_t)L_5;
		return;
	}
}
// Method Definition Index: 11536
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_ThrowForEmptyQueue_mFD35ACF4F6124F6620C9C26DC1F87AD2A188AAC0_gshared (Queue_1_t3FE0612D3B8DC51012B66D1F29492192E2F95BFB* __this, const RuntimeMethod* method) 
{
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_0 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1102619AA6FB2A4AADBDAA47DDC096AE04C772C0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 79518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) 
{
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		__this->____mainTreeNodeId = L_4;
		int32_t* L_5 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_5, sizeof(int32_t));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E_AdjustorThunk (RuntimeObject* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E(_thisAdjusted, ___0_tree, method);
}
// Method Definition Index: 79519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		int32_t* L_8 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_6);
		int32_t L_9;
		L_9 = RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), L_8, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		__this->____index = L_9;
		int32_t L_10 = __this->____index;
		if (L_10)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_11;
		L_11 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0050:
	{
		int32_t* L_12 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_12, sizeof(int32_t));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA_AdjustorThunk (RuntimeObject* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA(_thisAdjusted, ___0_tree, ___1_position, method);
}
// Method Definition Index: 79520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	RBTreeEnumerator_Dispose_m50245E360872FE628842184531D36E037399CE20(_thisAdjusted, method);
}
// Method Definition Index: 79521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = __this->____tree;
		int32_t* L_5 = (int32_t*)(&__this->____index);
		int32_t* L_6 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_4);
		bool L_7;
		L_7 = RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE(L_4, L_5, L_6, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4));
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_8 = __this->____tree;
		int32_t L_9 = __this->____index;
		NullCheck(L_8);
		int32_t L_10;
		L_10 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5));
		__this->____current = L_10;
		return L_7;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2), &L_1);
		return L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4_gshared (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = __this->____tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		int32_t* L_6 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_6, sizeof(int32_t));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115*>(__this + _offset);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 79518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method) 
{
	{
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		__this->____index = 0;
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		__this->____mainTreeNodeId = L_4;
		RuntimeObject** L_5 = (RuntimeObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_5, sizeof(RuntimeObject*));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700_AdjustorThunk (RuntimeObject* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700(_thisAdjusted, ___0_tree, method);
}
// Method Definition Index: 79519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	{
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		__this->____index = 0;
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		int32_t* L_8 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_6);
		int32_t L_9;
		L_9 = RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), L_8, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		__this->____index = L_9;
		int32_t L_10 = __this->____index;
		if (L_10)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_11;
		L_11 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0050:
	{
		RuntimeObject** L_12 = (RuntimeObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_12, sizeof(RuntimeObject*));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D_AdjustorThunk (RuntimeObject* __this, RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RBTreeEnumerator__ctor_m6E21AC6C4E86A24D602CD91F46425928C4ADF82D(_thisAdjusted, ___0_tree, ___1_position, method);
}
// Method Definition Index: 79520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RBTreeEnumerator_Dispose_m1E08AEE7388530D346B9193B730D8B03273BF2A6(_thisAdjusted, method);
}
// Method Definition Index: 79521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____version;
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_4 = __this->____tree;
		int32_t* L_5 = (int32_t*)(&__this->____index);
		int32_t* L_6 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_4);
		bool L_7;
		L_7 = RBTree_1_Successor_m89C5DC61DF69FB7B614F570A01A91F8D4555D74A(L_4, L_5, L_6, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4));
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_8 = __this->____tree;
		int32_t L_9 = __this->____index;
		NullCheck(L_8);
		RuntimeObject* L_10;
		L_10 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5));
		__this->____current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____current), (void*)L_10);
		return L_7;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_m76DBA6D87BDD9AE92D0E1B8AA83CBCA809AF2C5E(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0;
		L_0 = RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_inline(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
		return L_0;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mE3D8BAC55EE728E4B5EC5C2CA70730160709EB5A(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50_gshared (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____version;
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		__this->____index = 0;
		RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* L_4 = __this->____tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		RuntimeObject** L_6 = (RuntimeObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_6, sizeof(RuntimeObject*));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A*>(__this + _offset);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m9B4501D17EEC9E2B952126A9678DEEB960C8CA50(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 79518
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_0 = ___0_tree;
		il2cpp_codegen_write_instance_field_data<RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0), L_0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),1), L_2);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),3), L_4);
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_AdjustorThunk (RuntimeObject* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB(_thisAdjusted, ___0_tree, method);
}
// Method Definition Index: 79519
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_0 = ___0_tree;
		il2cpp_codegen_write_instance_field_data<RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0), L_0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),1), L_2);
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),3), L_5);
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		NullCheck(L_6);
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3)))(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), (((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),3)))), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2), L_8);
		int32_t L_9 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2));
		if (L_9)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0050:
	{
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C_AdjustorThunk (RuntimeObject* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, int32_t ___1_position, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C(_thisAdjusted, ___0_tree, ___1_position, method);
}
// Method Definition Index: 79520
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955(_thisAdjusted, method);
}
// Method Definition Index: 79521
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),1));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0));
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0));
		NullCheck(L_4);
		bool L_5;
		L_5 = ((  bool (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t*, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4)))(L_4, (((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2)))), (((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),3)))), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_6 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0));
		int32_t L_7 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2));
		NullCheck(L_6);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5), L_6, L_7, (Il2CppFullySharedGenericAny*)L_8);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4), L_8, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return L_5;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79522
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4)), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_inline(_thisAdjusted, il2cppRetVal, method);
	return;
}
// Method Definition Index: 79523
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6), __this, (Il2CppFullySharedGenericAny*)L_0);
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2), L_0);
		return L_1;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 79524
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_gshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),1));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0));
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),2), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0));
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),3), L_5);
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*>(__this + _offset);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 79450
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1__ctor_m94D0C9F06C7211AEA1E7596028FE173C1C787497_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_accessMethod, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_accessMethod;
		__this->____accessMethod = L_0;
		RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 1));
		return;
	}
}
// Method Definition Index: 79451
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		__this->___root = 0;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = (TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)(TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 2), (uint32_t)((int32_t)32));
		__this->____pageTable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_0);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_1 = __this->____pageTable;
		NullCheck(L_1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_1)->max_length)), ((int32_t)32))), 1))/((int32_t)32))));
		__this->____pageTableMap = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_2);
		__this->____inUsePageCount = 0;
		__this->____nextFreePageLine = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3;
		L_3 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)32), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_4 = __this->____pageTable;
		NullCheck(L_4);
		int32_t L_5 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		NullCheck(L_6);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_7 = L_6->____slots;
		NullCheck(L_7);
		((L_7)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->____nodeColor = (int32_t)1;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_8 = __this->____pageTable;
		NullCheck(L_8);
		int32_t L_9 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_10 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		NullCheck(L_10);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = L_10->____slotMap;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(0), (int32_t)1);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_12 = __this->____pageTable;
		NullCheck(L_12);
		int32_t L_13 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_14 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline(L_14, 1, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		__this->____inUseNodeCount = 1;
		__this->____inUseSatelliteTreeCount = 0;
		return;
	}
}
// Method Definition Index: 79452
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_0 = ___0_page;
		RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_1 = __this->____pageTable;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_2 = ___0_page;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, NULL);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)NULL);
		int32_t L_4 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		return;
	}
}
// Method Definition Index: 79453
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_0029;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_2 = __this->____pageTable;
		int32_t L_3 = V_0;
		int32_t L_4 = ___0_size;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 5));
		TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83(L_5, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)L_5);
		int32_t L_6 = V_0;
		__this->____nextFreePageLine = ((int32_t)(L_6/((int32_t)32)));
		goto IL_00a9;
	}

IL_0029:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_7 = __this->____pageTable;
		NullCheck(L_7);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_8 = (TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)(TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 2), (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_7)->max_length)), 2)));
		V_1 = L_8;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_9 = __this->____pageTable;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_10 = V_1;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_11 = __this->____pageTable;
		NullCheck(L_11);
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, ((int32_t)(((RuntimeArray*)L_11)->max_length)), NULL);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_12 = V_1;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_12)->max_length)), ((int32_t)32))), 1))/((int32_t)32))));
		V_2 = L_13;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = __this->____pageTableMap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = __this->____pageTableMap;
		NullCheck(L_16);
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, 0, ((int32_t)(((RuntimeArray*)L_16)->max_length)), NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = __this->____pageTableMap;
		NullCheck(L_17);
		__this->____nextFreePageLine = ((int32_t)(((RuntimeArray*)L_17)->max_length));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_18 = __this->____pageTable;
		NullCheck(L_18);
		V_0 = ((int32_t)(((RuntimeArray*)L_18)->max_length));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_19 = V_1;
		__this->____pageTable = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_19);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_20 = V_2;
		__this->____pageTableMap = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_20);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_21 = __this->____pageTable;
		int32_t L_22 = V_0;
		int32_t L_23 = ___0_size;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 5));
		TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83(L_24, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(L_22), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)L_24);
	}

IL_00a9:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_25 = __this->____pageTable;
		int32_t L_26 = V_0;
		NullCheck(L_25);
		int32_t L_27 = L_26;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_28 = (L_25)->GetAt(static_cast<il2cpp_array_size_t>(L_27));
		int32_t L_29 = V_0;
		NullCheck(L_28);
		TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_inline(L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		int32_t L_30 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_add(L_30, 1));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_31 = __this->____pageTable;
		int32_t L_32 = V_0;
		NullCheck(L_31);
		int32_t L_33 = L_32;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_34 = (L_31)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		return L_34;
	}
}
// Method Definition Index: 79454
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFull_mC50FFD42DDEC1D8C70AB4B76EA8E765F43D1A138_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *((int32_t*)L_3);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		*((int32_t*)L_3) = (int32_t)((int32_t)(L_4|((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))));
		return;
	}
}
// Method Definition Index: 79455
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *((int32_t*)L_3);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		*((int32_t*)L_3) = (int32_t)((int32_t)(L_4&((~((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))))));
		return;
	}
}
// Method Definition Index: 79456
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56_gshared (uint32_t ___0_bitMap, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = 0;
		uint32_t L_0 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_0&((int32_t)-65536))))
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		uint32_t L_2 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_2>>((int32_t)16)));
	}

IL_0016:
	{
		uint32_t L_3 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_3&((int32_t)65280))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_4, 8));
		uint32_t L_5 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_5>>8));
	}

IL_0028:
	{
		uint32_t L_6 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_6&((int32_t)240))))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_7 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, 4));
		uint32_t L_8 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_8>>4));
	}

IL_003a:
	{
		uint32_t L_9 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_9&((int32_t)12))))
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 2));
		uint32_t L_11 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_11>>2));
	}

IL_0049:
	{
		uint32_t L_12 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_12&2)))
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0052:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		V_0 = L_3;
		int32_t L_4 = ___0_nodeId;
		V_1 = ((int32_t)(L_4&((int32_t)65535)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = V_0;
		NullCheck(L_5);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_6 = L_5->____slots;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		il2cpp_codegen_initobj(((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7))), sizeof(Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_8 = V_0;
		NullCheck(L_8);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = L_8->____slotMap;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		int32_t* L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_10/((int32_t)32))))));
		int32_t L_12 = *((int32_t*)L_11);
		int32_t L_13 = V_1;
		*((int32_t*)L_11) = (int32_t)((int32_t)(L_12&((~((int32_t)(1<<((int32_t)(((int32_t)(L_13%((int32_t)32)))&((int32_t)31)))))))));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_14 = V_0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_15 = L_14;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		V_2 = L_16;
		int32_t L_17 = V_2;
		NullCheck(L_15);
		TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline(L_15, ((int32_t)il2cpp_codegen_subtract(L_17, 1)), il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		int32_t L_18 = __this->____inUseNodeCount;
		__this->____inUseNodeCount = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_19 = V_0;
		NullCheck(L_19);
		int32_t L_20;
		L_20 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		if (L_20)
		{
			goto IL_0071;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_21 = V_0;
		RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C(__this, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		return;
	}

IL_0071:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23;
		L_23 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = V_0;
		NullCheck(L_24);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_25 = L_24->____slots;
		NullCheck(L_25);
		if ((!(((uint32_t)L_23) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_25)->max_length)), 1))))))
		{
			goto IL_008a;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_26 = V_0;
		RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB(__this, L_26, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
	}

IL_008a:
	{
		return;
	}
}
// Method Definition Index: 79458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	uint32_t V_3 = 0;
	{
		int32_t L_0 = __this->____nextFreePageLine;
		V_0 = L_0;
		V_1 = (-1);
		goto IL_0073;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____pageTableMap;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if ((!(((uint32_t)L_4) < ((uint32_t)(-1)))))
		{
			goto IL_006f;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____pageTableMap;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_2 = (uint32_t)L_8;
		goto IL_006a;
	}

IL_0021:
	{
		uint32_t L_9 = V_2;
		uint32_t L_10 = V_2;
		V_3 = (uint32_t)((int32_t)(((~((int32_t)L_9)))&((int32_t)il2cpp_codegen_add((int32_t)L_10, 1))));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____pageTableMap;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		uint32_t L_15 = V_3;
		if (!((int64_t)(((int64_t)L_14)&((int64_t)(uint64_t)((uint32_t)L_15)))))
		{
			goto IL_003d;
		}
	}
	{
		Exception_t* L_16;
		L_16 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)3, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_003d:
	{
		int32_t L_17 = V_0;
		uint32_t L_18 = V_3;
		int32_t L_19;
		L_19 = RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56(L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 17));
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_17, ((int32_t)32))), L_19));
		bool L_20 = ___0_allocatedPage;
		if (!L_20)
		{
			goto IL_0058;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_21 = __this->____pageTable;
		int32_t L_22 = V_1;
		NullCheck(L_21);
		int32_t L_23 = L_22;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = (L_21)->GetAt(static_cast<il2cpp_array_size_t>(L_23));
		if (!L_24)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_25 = V_1;
		return L_25;
	}

IL_0058:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_26 = __this->____pageTable;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		int32_t L_28 = L_27;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_29 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_28));
		if (L_29)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_30 = V_1;
		return L_30;
	}

IL_0064:
	{
		V_1 = (-1);
		uint32_t L_31 = V_2;
		uint32_t L_32 = V_3;
		V_2 = (uint32_t)((int32_t)((int32_t)L_31|(int32_t)L_32));
	}

IL_006a:
	{
		uint32_t L_33 = V_2;
		if (((int32_t)((int32_t)L_33^(-1))))
		{
			goto IL_0021;
		}
	}

IL_006f:
	{
		int32_t L_34 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_0073:
	{
		int32_t L_35 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = __this->____pageTableMap;
		NullCheck(L_36);
		if ((((int32_t)L_35) < ((int32_t)((int32_t)(((RuntimeArray*)L_36)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		int32_t L_37 = __this->____nextFreePageLine;
		if (!L_37)
		{
			goto IL_0095;
		}
	}
	{
		__this->____nextFreePageLine = 0;
		bool L_38 = ___0_allocatedPage;
		int32_t L_39;
		L_39 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, L_38, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_1 = L_39;
	}

IL_0095:
	{
		int32_t L_40 = V_1;
		return L_40;
	}
}
// Method Definition Index: 79459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseNodeCount;
		return ((int32_t)il2cpp_codegen_subtract(L_0, 1));
	}
}
// Method Definition Index: 79460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_get_HasDuplicates_m4F156E4EE63FDA1D6F9A8FC9E85FDCEA272E3F72_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		return (bool)((!(((uint32_t)L_0) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 79461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)NULL;
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, (bool)1, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_1 = L_0;
		int32_t L_1 = V_1;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001c;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_2 = __this->____pageTable;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_0 = L_5;
		goto IL_00a5;
	}

IL_001c:
	{
		int32_t L_6 = __this->____inUsePageCount;
		if ((((int32_t)L_6) >= ((int32_t)4)))
		{
			goto IL_0030;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_7;
		L_7 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)32), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_7;
		goto IL_00a5;
	}

IL_0030:
	{
		int32_t L_8 = __this->____inUsePageCount;
		if ((((int32_t)L_8) >= ((int32_t)((int32_t)32))))
		{
			goto IL_0048;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_9;
		L_9 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)256), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_9;
		goto IL_00a5;
	}

IL_0048:
	{
		int32_t L_10 = __this->____inUsePageCount;
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)128))))
		{
			goto IL_0063;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_11;
		L_11 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)1024), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_11;
		goto IL_00a5;
	}

IL_0063:
	{
		int32_t L_12 = __this->____inUsePageCount;
		if ((((int32_t)L_12) >= ((int32_t)((int32_t)4096))))
		{
			goto IL_007e;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_13;
		L_13 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)4096), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_13;
		goto IL_00a5;
	}

IL_007e:
	{
		int32_t L_14 = __this->____inUsePageCount;
		if ((((int32_t)L_14) >= ((int32_t)((int32_t)32768))))
		{
			goto IL_0099;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_15;
		L_15 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)8192), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_15;
		goto IL_00a5;
	}

IL_0099:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_16;
		L_16 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)65536), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_16;
	}

IL_00a5:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18;
		L_18 = TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329(L_17, __this, il2cpp_rgctx_method(method->klass->rgctx_data, 19));
		V_2 = L_18;
		int32_t L_19 = V_2;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_00b8;
		}
	}
	{
		Exception_t* L_20;
		L_20 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_00b8:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_21 = V_0;
		NullCheck(L_21);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_22 = L_21->____slots;
		int32_t L_23 = V_2;
		NullCheck(L_22);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = V_0;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		int32_t L_26 = V_2;
		((L_22)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_23)))->____selfId = ((int32_t)(((int32_t)(L_25<<((int32_t)16)))|L_26));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_27 = V_0;
		NullCheck(L_27);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_28 = L_27->____slots;
		int32_t L_29 = V_2;
		NullCheck(L_28);
		((L_28)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_29)))->____subTreeSize = 1;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_30 = V_0;
		NullCheck(L_30);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_31 = L_30->____slots;
		int32_t L_32 = V_2;
		NullCheck(L_31);
		int32_t L_33 = ___0_key;
		((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode = L_33;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_34 = V_0;
		NullCheck(L_34);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_35 = L_34->____slots;
		int32_t L_36 = V_2;
		NullCheck(L_35);
		int32_t L_37 = ((L_35)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_36)))->____selfId;
		return L_37;
	}
}
// Method Definition Index: 79462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_4;
		L_4 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		return L_4;
	}

IL_0017:
	{
		int32_t L_5 = ___0_x_id;
		int32_t L_6;
		L_6 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_0 = L_6;
		goto IL_002c;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		___0_x_id = L_7;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_0 = L_9;
	}

IL_002c:
	{
		int32_t L_10 = V_0;
		if (!L_10)
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_11 = ___0_x_id;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((((int32_t)L_11) == ((int32_t)L_13)))
		{
			goto IL_0021;
		}
	}

IL_0039:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_nodeId;
		int32_t L_1 = *((int32_t*)L_0);
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t* L_2 = ___0_nodeId;
		int32_t* L_3 = ___1_mainTreeNodeId;
		int32_t L_4 = *((int32_t*)L_3);
		int32_t L_5;
		L_5 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		*((int32_t*)L_2) = (int32_t)L_5;
		int32_t* L_6 = ___1_mainTreeNodeId;
		*((int32_t*)L_6) = (int32_t)0;
		goto IL_0032;
	}

IL_0013:
	{
		int32_t* L_7 = ___0_nodeId;
		int32_t* L_8 = ___0_nodeId;
		int32_t L_9 = *((int32_t*)L_8);
		int32_t L_10;
		L_10 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		*((int32_t*)L_7) = (int32_t)L_10;
		int32_t* L_11 = ___0_nodeId;
		int32_t L_12 = *((int32_t*)L_11);
		if (L_12)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_13 = ___1_mainTreeNodeId;
		int32_t L_14 = *((int32_t*)L_13);
		if (!L_14)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_15 = ___0_nodeId;
		int32_t* L_16 = ___1_mainTreeNodeId;
		int32_t L_17 = *((int32_t*)L_16);
		int32_t L_18;
		L_18 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_17, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		*((int32_t*)L_15) = (int32_t)L_18;
		int32_t* L_19 = ___1_mainTreeNodeId;
		*((int32_t*)L_19) = (int32_t)0;
	}

IL_0032:
	{
		int32_t* L_20 = ___0_nodeId;
		int32_t L_21 = *((int32_t*)L_20);
		if (!L_21)
		{
			goto IL_0062;
		}
	}
	{
		int32_t* L_22 = ___0_nodeId;
		int32_t L_23 = *((int32_t*)L_22);
		int32_t L_24;
		L_24 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_24)
		{
			goto IL_0060;
		}
	}
	{
		int32_t* L_25 = ___1_mainTreeNodeId;
		int32_t L_26 = *((int32_t*)L_25);
		if (!L_26)
		{
			goto IL_004c;
		}
	}
	{
		Exception_t* L_27;
		L_27 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)21), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_27, method);
	}

IL_004c:
	{
		int32_t* L_28 = ___1_mainTreeNodeId;
		int32_t* L_29 = ___0_nodeId;
		int32_t L_30 = *((int32_t*)L_29);
		*((int32_t*)L_28) = (int32_t)L_30;
		int32_t* L_31 = ___0_nodeId;
		int32_t* L_32 = ___0_nodeId;
		int32_t L_33 = *((int32_t*)L_32);
		int32_t L_34;
		L_34 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_35;
		L_35 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		*((int32_t*)L_31) = (int32_t)L_35;
	}

IL_0060:
	{
		return (bool)1;
	}

IL_0062:
	{
		return (bool)0;
	}
}
// Method Definition Index: 79464
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	{
		goto IL_000b;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		___0_x_id = L_1;
	}

IL_000b:
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (L_3)
		{
			goto IL_0002;
		}
	}
	{
		int32_t L_4 = ___0_x_id;
		return L_4;
	}
}
// Method Definition Index: 79465
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_2, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_10, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_17, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_19, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_26;
		L_26 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_25, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_31, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_33, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_35, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_47, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_61, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 79466
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_2, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_10, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_17, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_19, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_26;
		L_26 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_25, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_31, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_33, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_35, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_47, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_61, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 79467
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B54_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		V_0 = 0;
		int32_t L_1 = ___0_root_id;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_2 = ___0_root_id;
		G_B3_0 = L_2;
		goto IL_001c;
	}

IL_0016:
	{
		int32_t L_3 = __this->___root;
		G_B3_0 = L_3;
	}

IL_001c:
	{
		V_1 = G_B3_0;
		int32_t L_4 = __this->____accessMethod;
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_01f8;
		}
	}
	{
		bool L_5 = ___4_append;
		if (L_5)
		{
			goto IL_01f8;
		}
	}
	{
		goto IL_01f0;
	}

IL_0035:
	{
		int32_t L_6 = V_1;
		RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 35));
		int32_t L_7 = V_1;
		V_0 = L_7;
		int32_t L_8 = ___0_root_id;
		if (!L_8)
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_9 = ___1_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_11 = V_1;
		int32_t L_12;
		L_12 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_13;
		L_13 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_10, L_12);
		G_B9_0 = L_13;
		goto IL_006b;
	}

IL_0057:
	{
		int32_t L_14 = ___1_x_id;
		int32_t L_15;
		L_15 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_16 = V_1;
		int32_t L_17;
		L_17 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_18;
		L_18 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_15, L_17);
		G_B9_0 = L_18;
	}

IL_006b:
	{
		V_2 = G_B9_0;
		int32_t L_19 = V_2;
		if ((((int32_t)L_19) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_20 = V_1;
		int32_t L_21;
		L_21 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_1 = L_21;
		goto IL_01f0;
	}

IL_007d:
	{
		int32_t L_22 = V_2;
		if ((((int32_t)L_22) <= ((int32_t)0)))
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_23 = V_1;
		int32_t L_24;
		L_24 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_1 = L_24;
		goto IL_01f0;
	}

IL_008e:
	{
		int32_t L_25 = ___0_root_id;
		if (!L_25)
		{
			goto IL_0098;
		}
	}
	{
		Exception_t* L_26;
		L_26 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_26, method);
	}

IL_0098:
	{
		int32_t L_27 = V_1;
		int32_t L_28;
		L_28 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_28)
		{
			goto IL_00cd;
		}
	}
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_31 = ___1_x_id;
		int32_t L_32 = V_1;
		int32_t L_33;
		L_33 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, L_30, L_31, L_32, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		___0_root_id = L_33;
		int32_t L_34 = V_1;
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_37;
		L_37 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_34, L_37, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		goto IL_01ee;
	}

IL_00cd:
	{
		V_3 = 0;
		int32_t L_38 = V_1;
		int32_t L_39;
		L_39 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_38, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_40;
		L_40 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_3 = L_40;
		int32_t L_41 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = V_3;
		int32_t L_43 = V_1;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_42, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_44 = V_3;
		int32_t L_45 = V_1;
		int32_t L_46;
		L_46 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_44, L_46, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_47 = V_3;
		int32_t L_48 = V_1;
		int32_t L_49;
		L_49 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_47, L_49, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_50 = V_3;
		int32_t L_51 = V_1;
		int32_t L_52;
		L_52 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_51, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_50, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_53 = V_3;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_53, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_56 = V_1;
		int32_t L_57;
		L_57 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_58;
		L_58 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_57, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_59 = V_1;
		if ((!(((uint32_t)L_58) == ((uint32_t)L_59))))
		{
			goto IL_014b;
		}
	}
	{
		int32_t L_60 = V_1;
		int32_t L_61;
		L_61 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_62 = V_3;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_61, L_62, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0169;
	}

IL_014b:
	{
		int32_t L_63 = V_1;
		int32_t L_64;
		L_64 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_63, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_65;
		L_65 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_64, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_66 = V_1;
		if ((!(((uint32_t)L_65) == ((uint32_t)L_66))))
		{
			goto IL_0169;
		}
	}
	{
		int32_t L_67 = V_1;
		int32_t L_68;
		L_68 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_67, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_69 = V_3;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_68, L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0169:
	{
		int32_t L_70 = V_1;
		int32_t L_71;
		L_71 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_70, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_71)
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_72 = V_1;
		int32_t L_73;
		L_73 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_72, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_74 = V_3;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_73, L_74, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0180:
	{
		int32_t L_75 = V_1;
		int32_t L_76;
		L_76 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_75, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_76)
		{
			goto IL_0197;
		}
	}
	{
		int32_t L_77 = V_1;
		int32_t L_78;
		L_78 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_77, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_79 = V_3;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_78, L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0197:
	{
		int32_t L_80 = __this->___root;
		int32_t L_81 = V_1;
		if ((!(((uint32_t)L_80) == ((uint32_t)L_81))))
		{
			goto IL_01a7;
		}
	}
	{
		int32_t L_82 = V_3;
		__this->___root = L_82;
	}

IL_01a7:
	{
		int32_t L_83 = V_1;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_83, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_84 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_84, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_85 = V_1;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_85, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_86 = V_1;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_86, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_87 = V_1;
		int32_t L_88;
		L_88 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_87, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_4 = L_88;
		int32_t L_89 = V_1;
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_89, 1, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_90 = V_1;
		int32_t L_91 = ___1_x_id;
		int32_t L_92 = V_3;
		int32_t L_93;
		L_93 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, L_90, L_91, L_92, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		___0_root_id = L_93;
		int32_t L_94 = V_3;
		int32_t L_95 = V_4;
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_94, L_95, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_01ee:
	{
		int32_t L_96 = ___0_root_id;
		return L_96;
	}

IL_01f0:
	{
		int32_t L_97 = V_1;
		if (L_97)
		{
			goto IL_0035;
		}
	}
	{
		goto IL_0263;
	}

IL_01f8:
	{
		int32_t L_98 = __this->____accessMethod;
		bool L_99 = ___4_append;
		if (!((int32_t)(((((int32_t)L_98) == ((int32_t)2))? 1 : 0)|(int32_t)L_99)))
		{
			goto IL_025b;
		}
	}
	{
		int32_t L_100 = ___3_position;
		if ((!(((uint32_t)L_100) == ((uint32_t)(-1)))))
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_101 = __this->___root;
		int32_t L_102;
		L_102 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_101, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		___3_position = L_102;
		goto IL_0256;
	}

IL_021b:
	{
		int32_t L_103 = V_1;
		RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8(__this, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 35));
		int32_t L_104 = V_1;
		V_0 = L_104;
		int32_t L_105 = ___3_position;
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_108;
		L_108 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_107, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_105, L_108));
		int32_t L_109 = V_5;
		if ((((int32_t)L_109) > ((int32_t)0)))
		{
			goto IL_0245;
		}
	}
	{
		int32_t L_110 = V_1;
		int32_t L_111;
		L_111 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_110, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_1 = L_111;
		goto IL_0256;
	}

IL_0245:
	{
		int32_t L_112 = V_1;
		int32_t L_113;
		L_113 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_112, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_1 = L_113;
		int32_t L_114 = V_1;
		if (!L_114)
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_115 = V_5;
		___3_position = ((int32_t)il2cpp_codegen_subtract(L_115, 1));
	}

IL_0256:
	{
		int32_t L_116 = V_1;
		if (L_116)
		{
			goto IL_021b;
		}
	}
	{
		goto IL_0263;
	}

IL_025b:
	{
		Exception_t* L_117;
		L_117 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)15), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_117, method);
	}

IL_0263:
	{
		int32_t L_118 = ___1_x_id;
		int32_t L_119 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_118, L_119, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_120 = V_0;
		if (L_120)
		{
			goto IL_0298;
		}
	}
	{
		int32_t L_121 = ___0_root_id;
		if (L_121)
		{
			goto IL_027d;
		}
	}
	{
		int32_t L_122 = ___1_x_id;
		__this->___root = L_122;
		goto IL_030a;
	}

IL_027d:
	{
		int32_t L_123 = ___2_mainTreeNodeID;
		int32_t L_124 = ___1_x_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_123, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_125 = ___2_mainTreeNodeID;
		int32_t L_126 = ___1_x_id;
		int32_t L_127;
		L_127 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_126, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_125, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_128 = ___1_x_id;
		___0_root_id = L_128;
		goto IL_030a;
	}

IL_0298:
	{
		V_6 = 0;
		int32_t L_129 = __this->____accessMethod;
		if ((!(((uint32_t)L_129) == ((uint32_t)1))))
		{
			goto IL_02d5;
		}
	}
	{
		int32_t L_130 = ___0_root_id;
		if (!L_130)
		{
			goto IL_02bd;
		}
	}
	{
		int32_t L_131 = ___1_x_id;
		int32_t L_132;
		L_132 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_131, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_133 = V_0;
		int32_t L_134;
		L_134 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_133, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_135;
		L_135 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_132, L_134);
		G_B49_0 = L_135;
		goto IL_02d1;
	}

IL_02bd:
	{
		int32_t L_136 = ___1_x_id;
		int32_t L_137;
		L_137 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_136, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_138 = V_0;
		int32_t L_139;
		L_139 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_140;
		L_140 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_137, L_139);
		G_B49_0 = L_140;
	}

IL_02d1:
	{
		V_6 = G_B49_0;
		goto IL_02f3;
	}

IL_02d5:
	{
		int32_t L_141 = __this->____accessMethod;
		if ((!(((uint32_t)L_141) == ((uint32_t)2))))
		{
			goto IL_02eb;
		}
	}
	{
		int32_t L_142 = ___3_position;
		if ((((int32_t)L_142) <= ((int32_t)0)))
		{
			goto IL_02e6;
		}
	}
	{
		G_B54_0 = 1;
		goto IL_02e7;
	}

IL_02e6:
	{
		G_B54_0 = (-1);
	}

IL_02e7:
	{
		V_6 = G_B54_0;
		goto IL_02f3;
	}

IL_02eb:
	{
		Exception_t* L_143;
		L_143 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)16), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_143, method);
	}

IL_02f3:
	{
		int32_t L_144 = V_6;
		if ((((int32_t)L_144) >= ((int32_t)0)))
		{
			goto IL_0302;
		}
	}
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_145, L_146, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_030a;
	}

IL_0302:
	{
		int32_t L_147 = V_0;
		int32_t L_148 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_147, L_148, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_030a:
	{
		int32_t L_149 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_149, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_150 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_150, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_151 = ___1_x_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_151, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_152 = ___1_x_id;
		V_1 = L_152;
		goto IL_04ba;
	}

IL_0329:
	{
		int32_t L_153 = ___1_x_id;
		int32_t L_154;
		L_154 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_153, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_155 = ___1_x_id;
		int32_t L_156;
		L_156 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_155, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_157;
		L_157 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_156, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_158;
		L_158 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_157, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_154) == ((uint32_t)L_158))))
		{
			goto IL_0405;
		}
	}
	{
		int32_t L_159 = ___1_x_id;
		int32_t L_160;
		L_160 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_159, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_161;
		L_161 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_160, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_162;
		L_162 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_161, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_162;
		int32_t L_163 = V_0;
		int32_t L_164;
		L_164 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_163, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_164)
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_165 = ___1_x_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_165, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_166, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_167 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_167, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_168 = ___1_x_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_168, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_170;
		L_170 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_169, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_170, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_171 = ___1_x_id;
		int32_t L_172;
		L_172 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_171, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_173;
		L_173 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_172, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_173;
		goto IL_04ba;
	}

IL_03a3:
	{
		int32_t L_174 = ___1_x_id;
		int32_t L_175 = ___1_x_id;
		int32_t L_176;
		L_176 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_175, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_177;
		L_177 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_176, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_174) == ((uint32_t)L_177))))
		{
			goto IL_03c7;
		}
	}
	{
		int32_t L_178 = ___1_x_id;
		int32_t L_179;
		L_179 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_178, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_179;
		int32_t L_180 = ___0_root_id;
		int32_t L_181 = ___1_x_id;
		int32_t L_182 = ___2_mainTreeNodeID;
		int32_t L_183;
		L_183 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_180, L_181, L_182, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_183;
	}

IL_03c7:
	{
		int32_t L_184 = ___1_x_id;
		int32_t L_185;
		L_185 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_184, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_185, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_186 = ___1_x_id;
		int32_t L_187;
		L_187 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_186, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_188;
		L_188 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_187, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_188, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_189 = ___0_root_id;
		int32_t L_190 = ___1_x_id;
		int32_t L_191;
		L_191 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_190, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_192;
		L_192 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_191, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_193 = ___2_mainTreeNodeID;
		int32_t L_194;
		L_194 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_189, L_192, L_193, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_194;
		goto IL_04ba;
	}

IL_0405:
	{
		int32_t L_195 = ___1_x_id;
		int32_t L_196;
		L_196 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_195, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_197;
		L_197 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_196, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_198;
		L_198 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_197, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_198;
		int32_t L_199 = V_0;
		int32_t L_200;
		L_200 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_199, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_200)
		{
			goto IL_045d;
		}
	}
	{
		int32_t L_201 = ___1_x_id;
		int32_t L_202;
		L_202 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_201, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_202, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_203 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_203, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_204 = ___1_x_id;
		int32_t L_205;
		L_205 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_204, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_206;
		L_206 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_205, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_206, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_207 = ___1_x_id;
		int32_t L_208;
		L_208 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_207, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_209;
		L_209 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_208, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_209;
		goto IL_04ba;
	}

IL_045d:
	{
		int32_t L_210 = ___1_x_id;
		int32_t L_211 = ___1_x_id;
		int32_t L_212;
		L_212 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_211, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_213;
		L_213 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_212, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_210) == ((uint32_t)L_213))))
		{
			goto IL_0481;
		}
	}
	{
		int32_t L_214 = ___1_x_id;
		int32_t L_215;
		L_215 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_214, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_215;
		int32_t L_216 = ___0_root_id;
		int32_t L_217 = ___1_x_id;
		int32_t L_218 = ___2_mainTreeNodeID;
		int32_t L_219;
		L_219 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_216, L_217, L_218, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_219;
	}

IL_0481:
	{
		int32_t L_220 = ___1_x_id;
		int32_t L_221;
		L_221 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_220, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_221, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_222 = ___1_x_id;
		int32_t L_223;
		L_223 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_222, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_224;
		L_224 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_223, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_224, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_225 = ___0_root_id;
		int32_t L_226 = ___1_x_id;
		int32_t L_227;
		L_227 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_226, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_228;
		L_228 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_227, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_229 = ___2_mainTreeNodeID;
		int32_t L_230;
		L_230 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_225, L_228, L_229, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_230;
	}

IL_04ba:
	{
		int32_t L_231 = ___1_x_id;
		int32_t L_232;
		L_232 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_231, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_233;
		L_233 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_232, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (!L_233)
		{
			goto IL_0329;
		}
	}
	{
		int32_t L_234 = ___0_root_id;
		if (L_234)
		{
			goto IL_04de;
		}
	}
	{
		int32_t L_235 = __this->___root;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_235, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		goto IL_04e6;
	}

IL_04de:
	{
		int32_t L_236 = ___0_root_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_236, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
	}

IL_04e6:
	{
		int32_t L_237 = ___0_root_id;
		return L_237;
	}
}
// Method Definition Index: 79468
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_UpdateNodeKey_m90FF8C96E5A0A272D878A6CB88DEE893A34E6830_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_currentKey, int32_t ___1_newKey, const RuntimeMethod* method) 
{
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_currentKey;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_0 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_4)
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		int32_t L_7 = __this->___root;
		if ((((int32_t)L_6) == ((int32_t)L_7)))
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_8 = V_0;
		int32_t L_9 = L_8.____mainTreeNodeID;
		int32_t L_10 = ___1_newKey;
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_9, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_0031:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_11 = V_0;
		int32_t L_12 = L_11.____nodeID;
		int32_t L_13 = ___1_newKey;
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_12, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		return;
	}
}
// Method Definition Index: 79469
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method) 
{
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_i;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		V_0 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_7 = V_0;
		int32_t L_8 = L_7.____mainTreeNodeID;
		int32_t L_9;
		L_9 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, 0, L_6, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_4;
	}
}
// Method Definition Index: 79470
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDelete_mD650E7F92013005A24CE586C4FC1B71EE3D279C7_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_z_id, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_z_id;
		int32_t L_1;
		L_1 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, 0, L_0, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_1;
	}
}
// Method Definition Index: 79471
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t G_B5_0 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___1_z_id;
		int32_t L_1;
		L_1 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_1)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = ___1_z_id;
		int32_t L_3;
		L_3 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_4 = ___1_z_id;
		int32_t L_5;
		L_5 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_6 = ___1_z_id;
		int32_t L_7;
		L_7 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, L_3, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_7;
	}

IL_0021:
	{
		V_3 = (bool)0;
		int32_t L_8 = __this->____accessMethod;
		if ((((int32_t)L_8) == ((int32_t)1)))
		{
			goto IL_002f;
		}
	}
	{
		int32_t L_9 = ___1_z_id;
		G_B5_0 = L_9;
		goto IL_0030;
	}

IL_002f:
	{
		int32_t L_10 = ___2_mainTreeNodeID;
		G_B5_0 = L_10;
	}

IL_0030:
	{
		V_4 = G_B5_0;
		int32_t L_11 = V_4;
		int32_t L_12;
		L_12 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_12)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_13 = V_4;
		int32_t L_14;
		L_14 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		___0_root_id = L_14;
	}

IL_0046:
	{
		int32_t L_15 = V_4;
		int32_t L_16;
		L_16 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_17;
		L_17 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((!(((uint32_t)L_17) == ((uint32_t)2))))
		{
			goto IL_005b;
		}
	}
	{
		V_3 = (bool)1;
		goto IL_0073;
	}

IL_005b:
	{
		int32_t L_18 = V_4;
		int32_t L_19;
		L_19 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_20;
		L_20 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((!(((uint32_t)L_20) == ((uint32_t)1))))
		{
			goto IL_0073;
		}
	}
	{
		Exception_t* L_21;
		L_21 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)7, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_21, method);
	}

IL_0073:
	{
		int32_t L_22 = ___1_z_id;
		int32_t L_23;
		L_23 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_23)
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_24 = ___1_z_id;
		int32_t L_25;
		L_25 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (L_25)
		{
			goto IL_0089;
		}
	}

IL_0085:
	{
		int32_t L_26 = ___1_z_id;
		V_1 = L_26;
		goto IL_0091;
	}

IL_0089:
	{
		int32_t L_27 = ___1_z_id;
		int32_t L_28;
		L_28 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_28;
	}

IL_0091:
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_30)
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_31 = V_1;
		int32_t L_32;
		L_32 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_31, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_32;
		goto IL_00ac;
	}

IL_00a4:
	{
		int32_t L_33 = V_1;
		int32_t L_34;
		L_34 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_34;
	}

IL_00ac:
	{
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_2 = L_36;
		int32_t L_37 = V_0;
		if (!L_37)
		{
			goto IL_00bf;
		}
	}
	{
		int32_t L_38 = V_0;
		int32_t L_39 = V_2;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_38, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_00bf:
	{
		int32_t L_40 = V_2;
		if (L_40)
		{
			goto IL_00d3;
		}
	}
	{
		int32_t L_41 = ___0_root_id;
		if (L_41)
		{
			goto IL_00ce;
		}
	}
	{
		int32_t L_42 = V_0;
		__this->___root = L_42;
		goto IL_00ef;
	}

IL_00ce:
	{
		int32_t L_43 = V_0;
		___0_root_id = L_43;
		goto IL_00ef;
	}

IL_00d3:
	{
		int32_t L_44 = V_1;
		int32_t L_45 = V_2;
		int32_t L_46;
		L_46 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_44) == ((uint32_t)L_46))))
		{
			goto IL_00e7;
		}
	}
	{
		int32_t L_47 = V_2;
		int32_t L_48 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_47, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_00ef;
	}

IL_00e7:
	{
		int32_t L_49 = V_2;
		int32_t L_50 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_49, L_50, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_00ef:
	{
		int32_t L_51 = V_1;
		int32_t L_52 = ___1_z_id;
		if ((((int32_t)L_51) == ((int32_t)L_52)))
		{
			goto IL_010f;
		}
	}
	{
		int32_t L_53 = ___1_z_id;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_53, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_56 = ___1_z_id;
		int32_t L_57 = V_1;
		int32_t L_58;
		L_58 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_57, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_56, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
	}

IL_010f:
	{
		int32_t L_59 = V_4;
		int32_t L_60;
		L_60 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_60)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_61 = ___0_root_id;
		if (L_61)
		{
			goto IL_0128;
		}
	}
	{
		int32_t L_62 = ___1_z_id;
		int32_t L_63 = V_4;
		if ((((int32_t)L_62) == ((int32_t)L_63)))
		{
			goto IL_0128;
		}
	}
	{
		Exception_t* L_64;
		L_64 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_64, method);
	}

IL_0128:
	{
		int32_t L_65 = ___0_root_id;
		if (!L_65)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_66 = V_4;
		int32_t L_67 = ___0_root_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_66, L_67, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_68 = V_4;
		int32_t L_69 = ___0_root_id;
		int32_t L_70;
		L_70 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_68, L_70, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_0143:
	{
		int32_t L_71 = V_2;
		V_5 = L_71;
		goto IL_015a;
	}

IL_0148:
	{
		int32_t L_72 = V_5;
		RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A(__this, L_72, il2cpp_rgctx_method(method->klass->rgctx_data, 48));
		int32_t L_73 = V_5;
		int32_t L_74;
		L_74 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_73, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_5 = L_74;
	}

IL_015a:
	{
		int32_t L_75 = V_5;
		if (L_75)
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_76 = ___0_root_id;
		if (!L_76)
		{
			goto IL_017d;
		}
	}
	{
		int32_t L_77 = V_4;
		V_6 = L_77;
		goto IL_0179;
	}

IL_0167:
	{
		int32_t L_78 = V_6;
		RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F(__this, L_78, il2cpp_rgctx_method(method->klass->rgctx_data, 49));
		int32_t L_79 = V_6;
		int32_t L_80;
		L_80 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_6 = L_80;
	}

IL_0179:
	{
		int32_t L_81 = V_6;
		if (L_81)
		{
			goto IL_0167;
		}
	}

IL_017d:
	{
		int32_t L_82 = V_1;
		int32_t L_83;
		L_83 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_82, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_83) == ((uint32_t)1))))
		{
			goto IL_0193;
		}
	}
	{
		int32_t L_84 = ___0_root_id;
		int32_t L_85 = V_0;
		int32_t L_86 = V_2;
		int32_t L_87 = ___2_mainTreeNodeID;
		int32_t L_88;
		L_88 = RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89(__this, L_84, L_85, L_86, L_87, il2cpp_rgctx_method(method->klass->rgctx_data, 50));
		___0_root_id = L_88;
	}

IL_0193:
	{
		bool L_89 = V_3;
		if (!L_89)
		{
			goto IL_02af;
		}
	}
	{
		int32_t L_90 = V_4;
		if (!L_90)
		{
			goto IL_01ae;
		}
	}
	{
		int32_t L_91 = V_4;
		int32_t L_92;
		L_92 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_91, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_93;
		L_93 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_92, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((((int32_t)L_93) == ((int32_t)1)))
		{
			goto IL_01b6;
		}
	}

IL_01ae:
	{
		Exception_t* L_94;
		L_94 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)9), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_94, method);
	}

IL_01b6:
	{
		int32_t L_95 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_subtract(L_95, 1));
		int32_t L_96 = V_4;
		int32_t L_97;
		L_97 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_96, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		V_7 = L_97;
		int32_t L_98 = V_7;
		int32_t L_99 = V_4;
		int32_t L_100;
		L_100 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_99, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_98, L_100, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_101 = V_7;
		int32_t L_102 = V_4;
		int32_t L_103;
		L_103 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_102, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_101, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_104 = V_7;
		int32_t L_105 = V_4;
		int32_t L_106;
		L_106 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_105, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_104, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_107 = V_7;
		int32_t L_108 = V_4;
		int32_t L_109;
		L_109 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_108, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_107, L_109, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_110 = V_4;
		int32_t L_111;
		L_111 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_110, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (!L_111)
		{
			goto IL_025c;
		}
	}
	{
		int32_t L_112 = V_7;
		int32_t L_113 = V_4;
		int32_t L_114;
		L_114 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_113, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_112, L_114, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_115 = V_4;
		int32_t L_116;
		L_116 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_115, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_117;
		L_117 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_116, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_118 = V_4;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_118))))
		{
			goto IL_024c;
		}
	}
	{
		int32_t L_119 = V_4;
		int32_t L_120;
		L_120 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_119, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_121 = V_7;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_120, L_121, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_025c;
	}

IL_024c:
	{
		int32_t L_122 = V_4;
		int32_t L_123;
		L_123 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_122, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_124 = V_7;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_123, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_025c:
	{
		int32_t L_125 = V_4;
		int32_t L_126;
		L_126 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_125, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_126)
		{
			goto IL_0276;
		}
	}
	{
		int32_t L_127 = V_4;
		int32_t L_128;
		L_128 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_129 = V_7;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_128, L_129, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0276:
	{
		int32_t L_130 = V_4;
		int32_t L_131;
		L_131 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_130, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_131)
		{
			goto IL_0290;
		}
	}
	{
		int32_t L_132 = V_4;
		int32_t L_133;
		L_133 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_132, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_134 = V_7;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_133, L_134, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0290:
	{
		int32_t L_135 = __this->___root;
		int32_t L_136 = V_4;
		if ((!(((uint32_t)L_135) == ((uint32_t)L_136))))
		{
			goto IL_02a2;
		}
	}
	{
		int32_t L_137 = V_7;
		__this->___root = L_137;
	}

IL_02a2:
	{
		int32_t L_138 = V_4;
		RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD(__this, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
		V_4 = 0;
		goto IL_02e4;
	}

IL_02af:
	{
		int32_t L_139 = V_4;
		int32_t L_140;
		L_140 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_139, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_140)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		if (L_141)
		{
			goto IL_02c9;
		}
	}
	{
		int32_t L_142 = ___1_z_id;
		int32_t L_143 = V_4;
		if ((((int32_t)L_142) == ((int32_t)L_143)))
		{
			goto IL_02c9;
		}
	}
	{
		Exception_t* L_144;
		L_144 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)10), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_144, method);
	}

IL_02c9:
	{
		int32_t L_145 = ___0_root_id;
		if (!L_145)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_146 = V_4;
		int32_t L_147 = ___0_root_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_146, L_147, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_148 = V_4;
		int32_t L_149 = ___0_root_id;
		int32_t L_150;
		L_150 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_149, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_148, L_150, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_02e4:
	{
		int32_t L_151 = V_1;
		int32_t L_152 = ___1_z_id;
		if ((((int32_t)L_151) == ((int32_t)L_152)))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_153 = V_1;
		int32_t L_154 = ___1_z_id;
		int32_t L_155;
		L_155 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_154, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_153, L_155, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_156 = V_1;
		int32_t L_157 = ___1_z_id;
		int32_t L_158;
		L_158 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_157, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_156, L_158, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_159 = V_1;
		int32_t L_160 = ___1_z_id;
		int32_t L_161;
		L_161 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_160, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_159, L_161, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_162 = V_1;
		int32_t L_163 = ___1_z_id;
		int32_t L_164;
		L_164 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_163, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_162, L_164, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_165 = ___1_z_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_165, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (!L_166)
		{
			goto IL_036a;
		}
	}
	{
		int32_t L_167 = V_1;
		int32_t L_168 = ___1_z_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_168, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_167, L_169, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_170 = ___1_z_id;
		int32_t L_171;
		L_171 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_170, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_172;
		L_172 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_171, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_173 = ___1_z_id;
		if ((!(((uint32_t)L_172) == ((uint32_t)L_173))))
		{
			goto IL_035a;
		}
	}
	{
		int32_t L_174 = ___1_z_id;
		int32_t L_175;
		L_175 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_174, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_176 = V_1;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_175, L_176, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0372;
	}

IL_035a:
	{
		int32_t L_177 = ___1_z_id;
		int32_t L_178;
		L_178 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_177, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_179 = V_1;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_178, L_179, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		goto IL_0372;
	}

IL_036a:
	{
		int32_t L_180 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_180, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0372:
	{
		int32_t L_181 = ___1_z_id;
		int32_t L_182;
		L_182 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_181, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_182)
		{
			goto IL_0389;
		}
	}
	{
		int32_t L_183 = ___1_z_id;
		int32_t L_184;
		L_184 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_183, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_185 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_184, L_185, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0389:
	{
		int32_t L_186 = ___1_z_id;
		int32_t L_187;
		L_187 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_186, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_187)
		{
			goto IL_03a0;
		}
	}
	{
		int32_t L_188 = ___1_z_id;
		int32_t L_189;
		L_189 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_188, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_190 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_189, L_190, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_03a0:
	{
		int32_t L_191 = __this->___root;
		int32_t L_192 = ___1_z_id;
		if ((!(((uint32_t)L_191) == ((uint32_t)L_192))))
		{
			goto IL_03b2;
		}
	}
	{
		int32_t L_193 = V_1;
		__this->___root = L_193;
		goto IL_03b9;
	}

IL_03b2:
	{
		int32_t L_194 = ___0_root_id;
		int32_t L_195 = ___1_z_id;
		if ((!(((uint32_t)L_194) == ((uint32_t)L_195))))
		{
			goto IL_03b9;
		}
	}
	{
		int32_t L_196 = V_1;
		___0_root_id = L_196;
	}

IL_03b9:
	{
		int32_t L_197 = V_4;
		if (!L_197)
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_198 = V_4;
		int32_t L_199;
		L_199 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_198, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_200 = ___1_z_id;
		if ((!(((uint32_t)L_199) == ((uint32_t)L_200))))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_201 = V_4;
		int32_t L_202 = V_1;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_201, L_202, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
	}

IL_03d1:
	{
		int32_t L_203 = ___1_z_id;
		RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD(__this, L_203, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
		int32_t L_204 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_204, 1));
		int32_t L_205 = ___1_z_id;
		return L_205;
	}
}
// Method Definition Index: 79472
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B24_0 = 0;
	int32_t G_B28_0 = 0;
	int32_t G_B34_0 = 0;
	int32_t G_B38_0 = 0;
	int32_t G_B47_0 = 0;
	int32_t G_B52_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B60_0 = 0;
	{
		int32_t L_0 = ___1_x_id;
		if (L_0)
		{
			goto IL_0305;
		}
	}
	{
		int32_t L_1 = ___2_px_id;
		if (L_1)
		{
			goto IL_0305;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		int32_t L_2 = ___1_x_id;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_3 = ___1_x_id;
		int32_t L_4 = ___1_x_id;
		int32_t L_5;
		L_5 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((((int32_t)L_3) == ((int32_t)L_6)))
		{
			goto IL_0033;
		}
	}

IL_0021:
	{
		int32_t L_7 = ___1_x_id;
		if (L_7)
		{
			goto IL_0168;
		}
	}
	{
		int32_t L_8 = ___2_px_id;
		int32_t L_9;
		L_9 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (L_9)
		{
			goto IL_0168;
		}
	}

IL_0033:
	{
		int32_t L_10 = ___1_x_id;
		if (!L_10)
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_13;
		L_13 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B10_0 = L_13;
		goto IL_004c;
	}

IL_0045:
	{
		int32_t L_14 = ___2_px_id;
		int32_t L_15;
		L_15 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B10_0 = L_15;
	}

IL_004c:
	{
		V_0 = G_B10_0;
		int32_t L_16 = V_0;
		if (L_16)
		{
			goto IL_0058;
		}
	}
	{
		Exception_t* L_17;
		L_17 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)14), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_0058:
	{
		int32_t L_18 = V_0;
		int32_t L_19;
		L_19 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_19)
		{
			goto IL_0097;
		}
	}
	{
		int32_t L_20 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_20, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_21 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_21, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_22 = ___0_root_id;
		int32_t L_23 = ___2_px_id;
		int32_t L_24 = ___3_mainTreeNodeID;
		int32_t L_25;
		L_25 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_22, L_23, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_25;
		int32_t L_26 = ___1_x_id;
		if (!L_26)
		{
			goto IL_008f;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29;
		L_29 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_28, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B16_0 = L_29;
		goto IL_0096;
	}

IL_008f:
	{
		int32_t L_30 = ___2_px_id;
		int32_t L_31;
		L_31 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B16_0 = L_31;
	}

IL_0096:
	{
		V_0 = G_B16_0;
	}

IL_0097:
	{
		int32_t L_32 = V_0;
		int32_t L_33;
		L_33 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_34;
		L_34 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_34) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_35 = V_0;
		int32_t L_36;
		L_36 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_37;
		L_37 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_37) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_38 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_38, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_39 = ___2_px_id;
		___1_x_id = L_39;
		int32_t L_40 = ___2_px_id;
		int32_t L_41;
		L_41 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_41;
		goto IL_0305;
	}

IL_00d0:
	{
		int32_t L_42 = V_0;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_44) == ((uint32_t)1))))
		{
			goto IL_011c;
		}
	}
	{
		int32_t L_45 = V_0;
		int32_t L_46;
		L_46 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_46, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_47 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_47, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_48 = ___0_root_id;
		int32_t L_49 = V_0;
		int32_t L_50 = ___3_mainTreeNodeID;
		int32_t L_51;
		L_51 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_48, L_49, L_50, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_51;
		int32_t L_52 = ___1_x_id;
		if (!L_52)
		{
			goto IL_0114;
		}
	}
	{
		int32_t L_53 = ___1_x_id;
		int32_t L_54;
		L_54 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_55;
		L_55 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B24_0 = L_55;
		goto IL_011b;
	}

IL_0114:
	{
		int32_t L_56 = ___2_px_id;
		int32_t L_57;
		L_57 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B24_0 = L_57;
	}

IL_011b:
	{
		V_0 = G_B24_0;
	}

IL_011c:
	{
		int32_t L_58 = V_0;
		int32_t L_59 = ___2_px_id;
		int32_t L_60;
		L_60 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_58, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_61 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_61, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_62 = V_0;
		int32_t L_63;
		L_63 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_62, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_63, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_64 = ___0_root_id;
		int32_t L_65 = ___2_px_id;
		int32_t L_66 = ___3_mainTreeNodeID;
		int32_t L_67;
		L_67 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_64, L_65, L_66, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_67;
		int32_t L_68 = ___0_root_id;
		if (!L_68)
		{
			goto IL_0152;
		}
	}
	{
		int32_t L_69 = ___0_root_id;
		G_B28_0 = L_69;
		goto IL_0158;
	}

IL_0152:
	{
		int32_t L_70 = __this->___root;
		G_B28_0 = L_70;
	}

IL_0158:
	{
		___1_x_id = G_B28_0;
		int32_t L_71 = ___1_x_id;
		int32_t L_72;
		L_72 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_71, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_72;
		goto IL_0305;
	}

IL_0168:
	{
		int32_t L_73 = ___2_px_id;
		int32_t L_74;
		L_74 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_73, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_74;
		int32_t L_75 = V_0;
		int32_t L_76;
		L_76 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_75, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_76)
		{
			goto IL_01ed;
		}
	}
	{
		int32_t L_77 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_77, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_78 = ___1_x_id;
		if (!L_78)
		{
			goto IL_01b4;
		}
	}
	{
		int32_t L_79 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_79, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_80 = ___0_root_id;
		int32_t L_81 = ___2_px_id;
		int32_t L_82 = ___3_mainTreeNodeID;
		int32_t L_83;
		L_83 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_80, L_81, L_82, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_83;
		int32_t L_84 = ___1_x_id;
		if (!L_84)
		{
			goto IL_01aa;
		}
	}
	{
		int32_t L_85 = ___1_x_id;
		int32_t L_86;
		L_86 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_85, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_87;
		L_87 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_86, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B34_0 = L_87;
		goto IL_01b1;
	}

IL_01aa:
	{
		int32_t L_88 = ___2_px_id;
		int32_t L_89;
		L_89 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_88, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B34_0 = L_89;
	}

IL_01b1:
	{
		V_0 = G_B34_0;
		goto IL_01ed;
	}

IL_01b4:
	{
		int32_t L_90 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_90, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_91 = ___0_root_id;
		int32_t L_92 = ___2_px_id;
		int32_t L_93 = ___3_mainTreeNodeID;
		int32_t L_94;
		L_94 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_91, L_92, L_93, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_94;
		int32_t L_95 = ___1_x_id;
		if (!L_95)
		{
			goto IL_01da;
		}
	}
	{
		int32_t L_96 = ___1_x_id;
		int32_t L_97;
		L_97 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_96, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_98;
		L_98 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_97, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B38_0 = L_98;
		goto IL_01e1;
	}

IL_01da:
	{
		int32_t L_99 = ___2_px_id;
		int32_t L_100;
		L_100 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_99, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B38_0 = L_100;
	}

IL_01e1:
	{
		V_0 = G_B38_0;
		int32_t L_101 = V_0;
		if (L_101)
		{
			goto IL_01ed;
		}
	}
	{
		Exception_t* L_102;
		L_102 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)11), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_102, method);
	}

IL_01ed:
	{
		int32_t L_103 = V_0;
		int32_t L_104;
		L_104 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_105;
		L_105 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_104, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_105) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_108;
		L_108 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_107, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_108) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_109 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_109, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_110 = ___2_px_id;
		___1_x_id = L_110;
		int32_t L_111 = ___2_px_id;
		int32_t L_112;
		L_112 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_111, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_112;
		goto IL_0305;
	}

IL_0226:
	{
		int32_t L_113 = V_0;
		int32_t L_114;
		L_114 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_113, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_115;
		L_115 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_114, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_115) == ((uint32_t)1))))
		{
			goto IL_0272;
		}
	}
	{
		int32_t L_116 = V_0;
		int32_t L_117;
		L_117 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_116, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_117, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_118 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_118, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_119 = ___0_root_id;
		int32_t L_120 = V_0;
		int32_t L_121 = ___3_mainTreeNodeID;
		int32_t L_122;
		L_122 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_119, L_120, L_121, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_122;
		int32_t L_123 = ___1_x_id;
		if (!L_123)
		{
			goto IL_026a;
		}
	}
	{
		int32_t L_124 = ___1_x_id;
		int32_t L_125;
		L_125 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_126;
		L_126 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_125, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B47_0 = L_126;
		goto IL_0271;
	}

IL_026a:
	{
		int32_t L_127 = ___2_px_id;
		int32_t L_128;
		L_128 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B47_0 = L_128;
	}

IL_0271:
	{
		V_0 = G_B47_0;
	}

IL_0272:
	{
		int32_t L_129 = ___1_x_id;
		if (!L_129)
		{
			goto IL_02be;
		}
	}
	{
		int32_t L_130 = V_0;
		int32_t L_131 = ___2_px_id;
		int32_t L_132;
		L_132 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_131, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_130, L_132, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_133 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_133, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_134 = V_0;
		int32_t L_135;
		L_135 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_134, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_135, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_136 = ___0_root_id;
		int32_t L_137 = ___2_px_id;
		int32_t L_138 = ___3_mainTreeNodeID;
		int32_t L_139;
		L_139 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_136, L_137, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_139;
		int32_t L_140 = ___0_root_id;
		if (!L_140)
		{
			goto IL_02ab;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		G_B52_0 = L_141;
		goto IL_02b1;
	}

IL_02ab:
	{
		int32_t L_142 = __this->___root;
		G_B52_0 = L_142;
	}

IL_02b1:
	{
		___1_x_id = G_B52_0;
		int32_t L_143 = ___1_x_id;
		int32_t L_144;
		L_144 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_143, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_144;
		goto IL_0305;
	}

IL_02be:
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___2_px_id;
		int32_t L_147;
		L_147 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_146, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_145, L_147, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_148 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_148, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_149 = V_0;
		int32_t L_150;
		L_150 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_149, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_150, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_151 = ___0_root_id;
		int32_t L_152 = ___2_px_id;
		int32_t L_153 = ___3_mainTreeNodeID;
		int32_t L_154;
		L_154 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_151, L_152, L_153, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_154;
		int32_t L_155 = ___0_root_id;
		if (!L_155)
		{
			goto IL_02f4;
		}
	}
	{
		int32_t L_156 = ___0_root_id;
		G_B56_0 = L_156;
		goto IL_02fa;
	}

IL_02f4:
	{
		int32_t L_157 = __this->___root;
		G_B56_0 = L_157;
	}

IL_02fa:
	{
		___1_x_id = G_B56_0;
		int32_t L_158 = ___1_x_id;
		int32_t L_159;
		L_159 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_158, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_159;
	}

IL_0305:
	{
		int32_t L_160 = ___0_root_id;
		if (!L_160)
		{
			goto IL_030b;
		}
	}
	{
		int32_t L_161 = ___0_root_id;
		G_B60_0 = L_161;
		goto IL_0311;
	}

IL_030b:
	{
		int32_t L_162 = __this->___root;
		G_B60_0 = L_162;
	}

IL_0311:
	{
		int32_t L_163 = ___1_x_id;
		if ((((int32_t)G_B60_0) == ((int32_t)L_163)))
		{
			goto IL_0321;
		}
	}
	{
		int32_t L_164 = ___1_x_id;
		int32_t L_165;
		L_165 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_164, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((((int32_t)L_165) == ((int32_t)1)))
		{
			goto IL_000e;
		}
	}

IL_0321:
	{
		int32_t L_166 = ___1_x_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_166, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_167 = ___0_root_id;
		return L_167;
	}
}
// Method Definition Index: 79473
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B10_0 = 0;
	{
		int32_t L_0 = ___0_root_id;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_1 = __this->____accessMethod;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0014;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)17), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_root_id;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_4 = ___0_root_id;
		G_B6_0 = L_4;
		goto IL_0020;
	}

IL_001a:
	{
		int32_t L_5 = __this->___root;
		G_B6_0 = L_5;
	}

IL_0020:
	{
		V_0 = G_B6_0;
		goto IL_005e;
	}

IL_0023:
	{
		int32_t L_6 = ___0_root_id;
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_7 = ___1_key;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_10;
		L_10 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_7, L_9);
		G_B10_0 = L_10;
		goto IL_0044;
	}

IL_0036:
	{
		int32_t L_11 = ___1_key;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_14;
		L_14 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_11, L_13);
		G_B10_0 = L_14;
	}

IL_0044:
	{
		V_1 = G_B10_0;
		int32_t L_15 = V_1;
		if (!L_15)
		{
			goto IL_0061;
		}
	}
	{
		int32_t L_16 = V_1;
		if ((((int32_t)L_16) >= ((int32_t)0)))
		{
			goto IL_0056;
		}
	}
	{
		int32_t L_17 = V_0;
		int32_t L_18;
		L_18 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_17, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_18;
		goto IL_005e;
	}

IL_0056:
	{
		int32_t L_19 = V_0;
		int32_t L_20;
		L_20 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_20;
	}

IL_005e:
	{
		int32_t L_21 = V_0;
		if (L_21)
		{
			goto IL_0023;
		}
	}

IL_0061:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 79474
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Item_m6CB743851EBBBD1D9007D28700324EA0002F3107_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		return L_3;
	}
}
// Method Definition Index: 79475
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, 0, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_3)
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_6 = ___0_key;
		int32_t L_7;
		L_7 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		int32_t L_8 = V_0;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_9;
		memset((&L_9), 0, sizeof(L_9));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_9), L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_9;
	}

IL_0027:
	{
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		V_1 = L_11;
		int32_t L_12 = ___0_key;
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 20), &L_13);
		bool L_15;
		L_15 = Int32_Equals_m089564150E8AF7C63B419427E2E57E3420659B1B((&V_1), L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 54));
		if (L_15)
		{
			goto IL_0046;
		}
	}
	{
		V_0 = 0;
	}

IL_0046:
	{
		int32_t L_16 = V_0;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_17;
		memset((&L_17), 0, sizeof(L_17));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_17), L_16, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_17;
	}
}
// Method Definition Index: 79476
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByKey_mB3893DE20533883A9097426F8B65C6548CE78176_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (-1);
		int32_t L_0 = ___0_key;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_1 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_1;
		int32_t L_3 = L_2.____nodeID;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_4 = V_1;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 55));
		V_0 = L_5;
	}

IL_001a:
	{
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 79477
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_node;
		int32_t L_2;
		L_2 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return L_2;
	}

IL_0010:
	{
		int32_t L_3 = ___0_node;
		int32_t L_4;
		L_4 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = ___0_node;
		int32_t L_6;
		L_6 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_6;
	}

IL_0021:
	{
		int32_t L_7 = ___0_node;
		int32_t L_8;
		L_8 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_9;
		L_9 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, 0, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		V_0 = L_9;
		int32_t L_10 = V_0;
		int32_t L_11 = ___0_node;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_12 = ___0_node;
		int32_t L_13;
		L_13 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_13;
	}

IL_003c:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		int32_t L_16 = ___0_node;
		int32_t L_17;
		L_17 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return ((int32_t)il2cpp_codegen_add(L_15, L_17));
	}
}
// Method Definition Index: 79478
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1 = ___0_path;
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return L_3;
	}

IL_0015:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_4 = ___0_path;
		int32_t L_5 = L_4.____mainTreeNodeID;
		if (L_5)
		{
			goto IL_002a;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_6 = ___0_path;
		int32_t L_7 = L_6.____nodeID;
		int32_t L_8;
		L_8 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_8;
	}

IL_002a:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_9 = ___0_path;
		int32_t L_10 = L_9.____mainTreeNodeID;
		int32_t L_11;
		L_11 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_12 = ___0_path;
		int32_t L_13 = L_12.____nodeID;
		int32_t L_14;
		L_14 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return ((int32_t)il2cpp_codegen_add(L_11, L_14));
	}
}
// Method Definition Index: 79479
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = L_2;
		goto IL_0037;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(L_11, 1))));
	}

IL_0034:
	{
		int32_t L_12 = V_1;
		___0_nodeId = L_12;
	}

IL_0037:
	{
		int32_t L_13 = ___0_nodeId;
		if (L_13)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79480
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B4_1 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B5_1 = 0;
	int32_t G_B5_2 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = L_2;
		goto IL_004f;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_12 = V_1;
		int32_t L_13;
		L_13 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_13)
		{
			G_B4_0 = L_11;
			G_B4_1 = L_8;
			goto IL_0048;
		}
		G_B3_0 = L_11;
		G_B3_1 = L_8;
	}
	{
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_16;
		L_16 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B5_0 = L_16;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0049;
	}

IL_0048:
	{
		G_B5_0 = 1;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0049:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B5_2, ((int32_t)il2cpp_codegen_add(G_B5_1, G_B5_0))));
	}

IL_004c:
	{
		int32_t L_17 = V_1;
		___0_nodeId = L_17;
	}

IL_004f:
	{
		int32_t L_18 = ___0_nodeId;
		if (L_18)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_19 = V_0;
		return L_19;
	}
}
// Method Definition Index: 79481
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1 = __this->___root;
		int32_t L_2 = ___0_userIndex;
		int32_t L_3;
		L_3 = RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064(__this, L_1, ((int32_t)il2cpp_codegen_add(L_2, 1)), il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		V_0 = L_3;
		V_1 = 0;
		goto IL_0026;
	}

IL_001c:
	{
		int32_t L_4 = ___0_userIndex;
		int32_t L_5;
		L_5 = RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751(__this, L_4, (&V_1), il2cpp_rgctx_method(method->klass->rgctx_data, 59));
		V_0 = L_5;
	}

IL_0026:
	{
		int32_t L_6 = V_0;
		if (L_6)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_7 = __this->____accessMethod;
		if ((!(((uint32_t)2) == ((uint32_t)L_7))))
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_8 = ___0_userIndex;
		Exception_t* L_9;
		L_9 = ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054(L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0039:
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0041:
	{
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_13;
		memset((&L_13), 0, sizeof(L_13));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_13), L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_13;
	}
}
// Method Definition Index: 79482
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_index;
		___0_index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t* L_1 = ___1_satelliteRootId;
		*((int32_t*)L_1) = (int32_t)0;
		int32_t L_2 = __this->___root;
		V_0 = L_2;
		V_1 = (-1);
		goto IL_0088;
	}

IL_0013:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = V_1;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_6;
		goto IL_0088;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_8)
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_11 = ___0_index;
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		int32_t L_14;
		L_14 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_15;
		L_15 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((((int32_t)L_11) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_12, L_15)), 1)))))
		{
			goto IL_005b;
		}
	}
	{
		int32_t* L_16 = ___1_satelliteRootId;
		int32_t L_17 = V_0;
		*((int32_t*)L_16) = (int32_t)L_17;
		int32_t L_18 = ___0_index;
		int32_t L_19 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_18, L_19)), 1));
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_22 = ___0_index;
		int32_t L_23;
		L_23 = RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064(__this, L_21, L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		return L_23;
	}

IL_005b:
	{
		int32_t L_24 = V_0;
		int32_t L_25;
		L_25 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (L_25)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_26 = ___0_index;
		int32_t L_27 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_26, L_27));
		goto IL_0080;
	}

IL_006b:
	{
		int32_t L_28 = ___0_index;
		int32_t L_29 = V_1;
		int32_t L_30 = V_0;
		int32_t L_31;
		L_31 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_32;
		L_32 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_31, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_28, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_29, L_32)), 1))));
	}

IL_0080:
	{
		int32_t L_33 = V_0;
		int32_t L_34;
		L_34 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_34;
	}

IL_0088:
	{
		int32_t L_35 = V_0;
		if (!L_35)
		{
			goto IL_00ae;
		}
	}
	{
		int32_t L_36 = V_0;
		int32_t L_37;
		L_37 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_38;
		L_38 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_37, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_39 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		V_1 = L_39;
		int32_t L_40 = ___0_index;
		if ((!(((uint32_t)L_39) == ((uint32_t)L_40))))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_41 = V_0;
		int32_t L_42;
		L_42 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_41, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (L_42)
		{
			goto IL_0013;
		}
	}

IL_00ae:
	{
		int32_t L_43 = V_0;
		return L_43;
	}
}
// Method Definition Index: 79483
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		goto IL_002f;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
		int32_t L_4 = ___1_index;
		int32_t L_5 = V_1;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_6 = V_0;
		___0_x_id = L_6;
		goto IL_002f;
	}

IL_001d:
	{
		int32_t L_7 = V_1;
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_9 = ___0_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		___0_x_id = L_10;
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_1;
		___1_index = ((int32_t)il2cpp_codegen_subtract(L_11, L_12));
	}

IL_002f:
	{
		int32_t L_13 = ___0_x_id;
		if (L_13)
		{
			goto IL_0002;
		}
	}

IL_0032:
	{
		int32_t L_14 = ___0_x_id;
		return L_14;
	}
}
// Method Definition Index: 79484
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m42434109EC7D9962C6C5C151208BB39B7F503419_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 79485
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Add_m89D1F5C6465A94C01A47855B3966C06B69E55969_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 79486
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_GetEnumerator_m69FD7C9F88127D1B135BFEA11640F79995101010_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	{
		RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 L_0;
		memset((&L_0), 0, sizeof(L_0));
		RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 61));
		RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 60), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 79487
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		int32_t L_0 = ___0_nodeId;
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_1 = ___0_nodeId;
		int32_t L_2;
		L_2 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 20), &L_3);
		int32_t L_5 = ___1_item;
		int32_t L_6 = L_5;
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 20), &L_6);
		if ((!(((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(RuntimeObject*)L_7))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 62));
		return L_9;
	}

IL_0021:
	{
		int32_t L_10 = ___0_nodeId;
		int32_t L_11;
		L_11 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_12 = ___1_item;
		int32_t L_13;
		L_13 = RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74(__this, L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
		int32_t L_14 = L_13;
		V_0 = L_14;
		if ((((int32_t)L_14) == ((int32_t)(-1))))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_15 = V_0;
		return L_15;
	}

IL_0036:
	{
		int32_t L_16 = ___0_nodeId;
		int32_t L_17;
		L_17 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_18 = ___1_item;
		int32_t L_19;
		L_19 = RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74(__this, L_17, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
		int32_t L_20 = L_19;
		V_0 = L_20;
		int32_t L_21 = V_0;
		return L_21;
	}

IL_004b:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 79488
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m0A0F524F3BD046708BD7A5DB13A4AA939D96D31C_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_position;
		int32_t L_1 = ___1_item;
		int32_t L_2;
		L_2 = RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F(__this, L_0, L_1, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 64));
		return L_2;
	}
}
// Method Definition Index: 79489
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = ___0_position;
		bool L_4 = ___2_append;
		int32_t L_5;
		L_5 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, L_3, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 79490
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RemoveAt_m08FF17CF03AA93867AE42791691F967386AFB716_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_position;
		int32_t L_1;
		L_1 = RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 65));
		return;
	}
}
// Method Definition Index: 79491
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Clear_m2FC29230F5DF876A67B0ABDCA2D2DE205166C385_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	{
		RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 1));
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		return;
	}
}
// Method Definition Index: 79492
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m8A396AD86818911F4C70E42BB8969FC6584093A3_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		V_0 = L_4;
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_5, NULL);
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_003a;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003a:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		V_1 = L_11;
		V_2 = 0;
		goto IL_006c;
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		int32_t L_13 = V_1;
		int32_t L_14;
		L_14 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 20), &L_15);
		int32_t L_17 = ___1_index;
		int32_t L_18 = V_2;
		NullCheck(L_12);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_12, L_16, ((int32_t)il2cpp_codegen_add(L_17, L_18)), NULL);
		int32_t L_19 = V_1;
		int32_t L_20;
		L_20 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_20;
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_006c:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004b;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 79493
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_mF41FDE1C3EB16CBA24B3F43FB7590B27E8612500_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		V_0 = L_4;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_5)->max_length)), L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0037;
		}
	}
	{
		Exception_t* L_8;
		L_8 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, method);
	}

IL_0037:
	{
		int32_t L_9 = __this->___root;
		int32_t L_10;
		L_10 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		V_1 = L_10;
		V_2 = 0;
		goto IL_0064;
	}

IL_0048:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = ___0_array;
		int32_t L_12 = ___1_index;
		int32_t L_13 = V_2;
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_12, L_13))), (int32_t)L_15);
		int32_t L_16 = V_1;
		int32_t L_17;
		L_17 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_17;
		int32_t L_18 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}

IL_0064:
	{
		int32_t L_19 = V_2;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) < ((int32_t)L_20)))
		{
			goto IL_0048;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 79494
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_rightNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId = L_6;
		return;
	}
}
// Method Definition Index: 79495
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_leftNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId = L_6;
		return;
	}
}
// Method Definition Index: 79496
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_parentNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId = L_6;
		return;
	}
}
// Method Definition Index: 79497
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_color;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor = L_6;
		return;
	}
}
// Method Definition Index: 79498
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_key;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode = L_6;
		return;
	}
}
// Method Definition Index: 79499
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_nextNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId = L_6;
		return;
	}
}
// Method Definition Index: 79500
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_size;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize = L_6;
		return;
	}
}
// Method Definition Index: 79501
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *((int32_t*)L_7);
		*((int32_t*)L_7) = (int32_t)((int32_t)il2cpp_codegen_add(L_8, 1));
		return;
	}
}
// Method Definition Index: 79502
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_5;
		L_5 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_7)
		{
			G_B2_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
			goto IL_0033;
		}
		G_B1_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_10;
		L_10 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B3_0 = L_10;
		G_B3_1 = G_B1_0;
		goto IL_0034;
	}

IL_0033:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0034:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B3_1, G_B3_0));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_11 = __this->____pageTable;
		int32_t L_12 = ___0_nodeId;
		NullCheck(L_11);
		int32_t L_13 = ((int32_t)(L_12>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_15 = L_14->____slots;
		int32_t L_16 = ___0_nodeId;
		NullCheck(L_15);
		int32_t L_17 = V_0;
		((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_16&((int32_t)65535))))))->____subTreeSize = L_17;
		return;
	}
}
// Method Definition Index: 79503
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *((int32_t*)L_7);
		*((int32_t*)L_7) = (int32_t)((int32_t)il2cpp_codegen_subtract(L_8, 1));
		return;
	}
}
// Method Definition Index: 79504
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId;
		return L_6;
	}
}
// Method Definition Index: 79505
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId;
		return L_6;
	}
}
// Method Definition Index: 79506
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId;
		return L_6;
	}
}
// Method Definition Index: 79507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor;
		return L_6;
	}
}
// Method Definition Index: 79508
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId;
		return L_6;
	}
}
// Method Definition Index: 79509
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize;
		return L_6;
	}
}
// Method Definition Index: 79510
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F_gshared (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 79450
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1__ctor_mDC88A4A9DD7DB95610C5C15AEC21E614AB37D778_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_accessMethod, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_accessMethod;
		__this->____accessMethod = L_0;
		RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 1));
		return;
	}
}
// Method Definition Index: 79451
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		__this->___root = 0;
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = (TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB*)(TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 2), (uint32_t)((int32_t)32));
		__this->____pageTable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_0);
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_1 = __this->____pageTable;
		NullCheck(L_1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_1)->max_length)), ((int32_t)32))), 1))/((int32_t)32))));
		__this->____pageTableMap = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_2);
		__this->____inUsePageCount = 0;
		__this->____nextFreePageLine = 0;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3;
		L_3 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)32), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_4 = __this->____pageTable;
		NullCheck(L_4);
		int32_t L_5 = 0;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		NullCheck(L_6);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_7 = L_6->____slots;
		NullCheck(L_7);
		((L_7)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->____nodeColor = (int32_t)1;
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_8 = __this->____pageTable;
		NullCheck(L_8);
		int32_t L_9 = 0;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_10 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		NullCheck(L_10);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = L_10->____slotMap;
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(0), (int32_t)1);
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_12 = __this->____pageTable;
		NullCheck(L_12);
		int32_t L_13 = 0;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_14 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_inline(L_14, 1, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		__this->____inUseNodeCount = 1;
		__this->____inUseSatelliteTreeCount = 0;
		return;
	}
}
// Method Definition Index: 79452
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_mD851F770281DBDCB21B4DA2CB84909655F0FA687_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method) 
{
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_0 = ___0_page;
		RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_1 = __this->____pageTable;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_2 = ___0_page;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, NULL);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)NULL);
		int32_t L_4 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		return;
	}
}
// Method Definition Index: 79453
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7(__this, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_0029;
		}
	}
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_2 = __this->____pageTable;
		int32_t L_3 = V_0;
		int32_t L_4 = ___0_size;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_5 = (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 5));
		TreePage__ctor_m6DC52E242F1727514B983F48EF264E12E82574EB(L_5, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)L_5);
		int32_t L_6 = V_0;
		__this->____nextFreePageLine = ((int32_t)(L_6/((int32_t)32)));
		goto IL_00a9;
	}

IL_0029:
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_7 = __this->____pageTable;
		NullCheck(L_7);
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_8 = (TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB*)(TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB*)SZArrayNew(il2cpp_rgctx_data(method->klass->rgctx_data, 2), (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_7)->max_length)), 2)));
		V_1 = L_8;
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_9 = __this->____pageTable;
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_10 = V_1;
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_11 = __this->____pageTable;
		NullCheck(L_11);
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, ((int32_t)(((RuntimeArray*)L_11)->max_length)), NULL);
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_12 = V_1;
		NullCheck(L_12);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_12)->max_length)), ((int32_t)32))), 1))/((int32_t)32))));
		V_2 = L_13;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = __this->____pageTableMap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = __this->____pageTableMap;
		NullCheck(L_16);
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_14, 0, (RuntimeArray*)L_15, 0, ((int32_t)(((RuntimeArray*)L_16)->max_length)), NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = __this->____pageTableMap;
		NullCheck(L_17);
		__this->____nextFreePageLine = ((int32_t)(((RuntimeArray*)L_17)->max_length));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_18 = __this->____pageTable;
		NullCheck(L_18);
		V_0 = ((int32_t)(((RuntimeArray*)L_18)->max_length));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_19 = V_1;
		__this->____pageTable = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_19);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_20 = V_2;
		__this->____pageTableMap = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_20);
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_21 = __this->____pageTable;
		int32_t L_22 = V_0;
		int32_t L_23 = ___0_size;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_24 = (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 5));
		TreePage__ctor_m6DC52E242F1727514B983F48EF264E12E82574EB(L_24, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(L_22), (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)L_24);
	}

IL_00a9:
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_25 = __this->____pageTable;
		int32_t L_26 = V_0;
		NullCheck(L_25);
		int32_t L_27 = L_26;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_28 = (L_25)->GetAt(static_cast<il2cpp_array_size_t>(L_27));
		int32_t L_29 = V_0;
		NullCheck(L_28);
		TreePage_set_PageId_m4637CDAE893DECB44B1201D9DFEF3C18C0DB5257_inline(L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		int32_t L_30 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_add(L_30, 1));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_31 = __this->____pageTable;
		int32_t L_32 = V_0;
		NullCheck(L_31);
		int32_t L_33 = L_32;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_34 = (L_31)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		return L_34;
	}
}
// Method Definition Index: 79454
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFull_mBC83115259A90BB0E08BF9B0C7991D7C82CD6471_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *((int32_t*)L_3);
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		*((int32_t*)L_3) = (int32_t)((int32_t)(L_4|((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))));
		return;
	}
}
// Method Definition Index: 79455
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* ___0_page, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *((int32_t*)L_3);
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		*((int32_t*)L_3) = (int32_t)((int32_t)(L_4&((~((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))))));
		return;
	}
}
// Method Definition Index: 79456
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_mDB63445CC664F05D6EEF8AB921EE44CD858E8F45_gshared (uint32_t ___0_bitMap, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = 0;
		uint32_t L_0 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_0&((int32_t)-65536))))
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		uint32_t L_2 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_2>>((int32_t)16)));
	}

IL_0016:
	{
		uint32_t L_3 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_3&((int32_t)65280))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_4, 8));
		uint32_t L_5 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_5>>8));
	}

IL_0028:
	{
		uint32_t L_6 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_6&((int32_t)240))))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_7 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, 4));
		uint32_t L_8 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_8>>4));
	}

IL_003a:
	{
		uint32_t L_9 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_9&((int32_t)12))))
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 2));
		uint32_t L_11 = ___0_bitMap;
		___0_bitMap = (uint32_t)((int32_t)((uint32_t)L_11>>2));
	}

IL_0049:
	{
		uint32_t L_12 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_12&2)))
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0052:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		V_0 = L_3;
		int32_t L_4 = ___0_nodeId;
		V_1 = ((int32_t)(L_4&((int32_t)65535)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_5 = V_0;
		NullCheck(L_5);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_6 = L_5->____slots;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		il2cpp_codegen_initobj(((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7))), sizeof(Node_t39E89F54A46CA848B0AED9F5454D71E99D318FDB));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_8 = V_0;
		NullCheck(L_8);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = L_8->____slotMap;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		int32_t* L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_10/((int32_t)32))))));
		int32_t L_12 = *((int32_t*)L_11);
		int32_t L_13 = V_1;
		*((int32_t*)L_11) = (int32_t)((int32_t)(L_12&((~((int32_t)(1<<((int32_t)(((int32_t)(L_13%((int32_t)32)))&((int32_t)31)))))))));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_14 = V_0;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_15 = L_14;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_inline(L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		V_2 = L_16;
		int32_t L_17 = V_2;
		NullCheck(L_15);
		TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_inline(L_15, ((int32_t)il2cpp_codegen_subtract(L_17, 1)), il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		int32_t L_18 = __this->____inUseNodeCount;
		__this->____inUseNodeCount = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_19 = V_0;
		NullCheck(L_19);
		int32_t L_20;
		L_20 = TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_inline(L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		if (L_20)
		{
			goto IL_0071;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_21 = V_0;
		RBTree_1_FreePage_mD851F770281DBDCB21B4DA2CB84909655F0FA687(__this, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		return;
	}

IL_0071:
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23;
		L_23 = TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_inline(L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_24 = V_0;
		NullCheck(L_24);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_25 = L_24->____slots;
		NullCheck(L_25);
		if ((!(((uint32_t)L_23) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_25)->max_length)), 1))))))
		{
			goto IL_008a;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_26 = V_0;
		RBTree_1_MarkPageFree_m1D298F02A27F4FBB8095CC09DDC73419066BED45(__this, L_26, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
	}

IL_008a:
	{
		return;
	}
}
// Method Definition Index: 79458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, bool ___0_allocatedPage, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	uint32_t V_3 = 0;
	{
		int32_t L_0 = __this->____nextFreePageLine;
		V_0 = L_0;
		V_1 = (-1);
		goto IL_0073;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____pageTableMap;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if ((!(((uint32_t)L_4) < ((uint32_t)(-1)))))
		{
			goto IL_006f;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____pageTableMap;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_2 = (uint32_t)L_8;
		goto IL_006a;
	}

IL_0021:
	{
		uint32_t L_9 = V_2;
		uint32_t L_10 = V_2;
		V_3 = (uint32_t)((int32_t)(((~((int32_t)L_9)))&((int32_t)il2cpp_codegen_add((int32_t)L_10, 1))));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____pageTableMap;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		uint32_t L_15 = V_3;
		if (!((int64_t)(((int64_t)L_14)&((int64_t)(uint64_t)((uint32_t)L_15)))))
		{
			goto IL_003d;
		}
	}
	{
		Exception_t* L_16;
		L_16 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)3, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_16, method);
	}

IL_003d:
	{
		int32_t L_17 = V_0;
		uint32_t L_18 = V_3;
		int32_t L_19;
		L_19 = RBTree_1_GetIntValueFromBitMap_mDB63445CC664F05D6EEF8AB921EE44CD858E8F45(L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 17));
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_17, ((int32_t)32))), L_19));
		bool L_20 = ___0_allocatedPage;
		if (!L_20)
		{
			goto IL_0058;
		}
	}
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_21 = __this->____pageTable;
		int32_t L_22 = V_1;
		NullCheck(L_21);
		int32_t L_23 = L_22;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_24 = (L_21)->GetAt(static_cast<il2cpp_array_size_t>(L_23));
		if (!L_24)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_25 = V_1;
		return L_25;
	}

IL_0058:
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_26 = __this->____pageTable;
		int32_t L_27 = V_1;
		NullCheck(L_26);
		int32_t L_28 = L_27;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_29 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_28));
		if (L_29)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_30 = V_1;
		return L_30;
	}

IL_0064:
	{
		V_1 = (-1);
		uint32_t L_31 = V_2;
		uint32_t L_32 = V_3;
		V_2 = (uint32_t)((int32_t)((int32_t)L_31|(int32_t)L_32));
	}

IL_006a:
	{
		uint32_t L_33 = V_2;
		if (((int32_t)((int32_t)L_33^(-1))))
		{
			goto IL_0021;
		}
	}

IL_006f:
	{
		int32_t L_34 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_0073:
	{
		int32_t L_35 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = __this->____pageTableMap;
		NullCheck(L_36);
		if ((((int32_t)L_35) < ((int32_t)((int32_t)(((RuntimeArray*)L_36)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		int32_t L_37 = __this->____nextFreePageLine;
		if (!L_37)
		{
			goto IL_0095;
		}
	}
	{
		__this->____nextFreePageLine = 0;
		bool L_38 = ___0_allocatedPage;
		int32_t L_39;
		L_39 = RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7(__this, L_38, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_1 = L_39;
	}

IL_0095:
	{
		int32_t L_40 = V_1;
		return L_40;
	}
}
// Method Definition Index: 79459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseNodeCount;
		return ((int32_t)il2cpp_codegen_subtract(L_0, 1));
	}
}
// Method Definition Index: 79460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_get_HasDuplicates_m9A29A98C3C392FFD5A3DD5E19BFF0BFB561DD7E1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		return (bool)((!(((uint32_t)L_0) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 79461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08*)NULL;
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_mB207A5B63C61CA6BA078E59E1E995360C81C43E7(__this, (bool)1, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		V_1 = L_0;
		int32_t L_1 = V_1;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001c;
		}
	}
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_2 = __this->____pageTable;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_0 = L_5;
		goto IL_00a5;
	}

IL_001c:
	{
		int32_t L_6 = __this->____inUsePageCount;
		if ((((int32_t)L_6) >= ((int32_t)4)))
		{
			goto IL_0030;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_7;
		L_7 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)32), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_7;
		goto IL_00a5;
	}

IL_0030:
	{
		int32_t L_8 = __this->____inUsePageCount;
		if ((((int32_t)L_8) >= ((int32_t)((int32_t)32))))
		{
			goto IL_0048;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_9;
		L_9 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)256), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_9;
		goto IL_00a5;
	}

IL_0048:
	{
		int32_t L_10 = __this->____inUsePageCount;
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)128))))
		{
			goto IL_0063;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_11;
		L_11 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)1024), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_11;
		goto IL_00a5;
	}

IL_0063:
	{
		int32_t L_12 = __this->____inUsePageCount;
		if ((((int32_t)L_12) >= ((int32_t)((int32_t)4096))))
		{
			goto IL_007e;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_13;
		L_13 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)4096), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_13;
		goto IL_00a5;
	}

IL_007e:
	{
		int32_t L_14 = __this->____inUsePageCount;
		if ((((int32_t)L_14) >= ((int32_t)((int32_t)32768))))
		{
			goto IL_0099;
		}
	}
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_15;
		L_15 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)8192), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_15;
		goto IL_00a5;
	}

IL_0099:
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_16;
		L_16 = RBTree_1_AllocPage_m215B88622A11B25D550D9105F141689D4EB4A839(__this, ((int32_t)65536), il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_0 = L_16;
	}

IL_00a5:
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18;
		L_18 = TreePage_AllocSlot_mEB4D7879BFA8750667B1902CA20FBF28279E1B52(L_17, __this, il2cpp_rgctx_method(method->klass->rgctx_data, 19));
		V_2 = L_18;
		int32_t L_19 = V_2;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_00b8;
		}
	}
	{
		Exception_t* L_20;
		L_20 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_00b8:
	{
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_21 = V_0;
		NullCheck(L_21);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_22 = L_21->____slots;
		int32_t L_23 = V_2;
		NullCheck(L_22);
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_24 = V_0;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_inline(L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		int32_t L_26 = V_2;
		((L_22)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_23)))->____selfId = ((int32_t)(((int32_t)(L_25<<((int32_t)16)))|L_26));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_27 = V_0;
		NullCheck(L_27);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_28 = L_27->____slots;
		int32_t L_29 = V_2;
		NullCheck(L_28);
		((L_28)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_29)))->____subTreeSize = 1;
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_30 = V_0;
		NullCheck(L_30);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_31 = L_30->____slots;
		int32_t L_32 = V_2;
		NullCheck(L_31);
		RuntimeObject* L_33 = ___0_key;
		((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode = L_33;
		Il2CppCodeGenWriteBarrier((void**)(&((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode), (void*)L_33);
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_34 = V_0;
		NullCheck(L_34);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_35 = L_34->____slots;
		int32_t L_36 = V_2;
		NullCheck(L_35);
		int32_t L_37 = ((L_35)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_36)))->____selfId;
		return L_37;
	}
}
// Method Definition Index: 79462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_4;
		L_4 = RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		return L_4;
	}

IL_0017:
	{
		int32_t L_5 = ___0_x_id;
		int32_t L_6;
		L_6 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_0 = L_6;
		goto IL_002c;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		___0_x_id = L_7;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_0 = L_9;
	}

IL_002c:
	{
		int32_t L_10 = V_0;
		if (!L_10)
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_11 = ___0_x_id;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((((int32_t)L_11) == ((int32_t)L_13)))
		{
			goto IL_0021;
		}
	}

IL_0039:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_m89C5DC61DF69FB7B614F570A01A91F8D4555D74A_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_nodeId;
		int32_t L_1 = *((int32_t*)L_0);
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t* L_2 = ___0_nodeId;
		int32_t* L_3 = ___1_mainTreeNodeId;
		int32_t L_4 = *((int32_t*)L_3);
		int32_t L_5;
		L_5 = RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		*((int32_t*)L_2) = (int32_t)L_5;
		int32_t* L_6 = ___1_mainTreeNodeId;
		*((int32_t*)L_6) = (int32_t)0;
		goto IL_0032;
	}

IL_0013:
	{
		int32_t* L_7 = ___0_nodeId;
		int32_t* L_8 = ___0_nodeId;
		int32_t L_9 = *((int32_t*)L_8);
		int32_t L_10;
		L_10 = RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		*((int32_t*)L_7) = (int32_t)L_10;
		int32_t* L_11 = ___0_nodeId;
		int32_t L_12 = *((int32_t*)L_11);
		if (L_12)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_13 = ___1_mainTreeNodeId;
		int32_t L_14 = *((int32_t*)L_13);
		if (!L_14)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_15 = ___0_nodeId;
		int32_t* L_16 = ___1_mainTreeNodeId;
		int32_t L_17 = *((int32_t*)L_16);
		int32_t L_18;
		L_18 = RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0(__this, L_17, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		*((int32_t*)L_15) = (int32_t)L_18;
		int32_t* L_19 = ___1_mainTreeNodeId;
		*((int32_t*)L_19) = (int32_t)0;
	}

IL_0032:
	{
		int32_t* L_20 = ___0_nodeId;
		int32_t L_21 = *((int32_t*)L_20);
		if (!L_21)
		{
			goto IL_0062;
		}
	}
	{
		int32_t* L_22 = ___0_nodeId;
		int32_t L_23 = *((int32_t*)L_22);
		int32_t L_24;
		L_24 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_24)
		{
			goto IL_0060;
		}
	}
	{
		int32_t* L_25 = ___1_mainTreeNodeId;
		int32_t L_26 = *((int32_t*)L_25);
		if (!L_26)
		{
			goto IL_004c;
		}
	}
	{
		Exception_t* L_27;
		L_27 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)21), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_27, method);
	}

IL_004c:
	{
		int32_t* L_28 = ___1_mainTreeNodeId;
		int32_t* L_29 = ___0_nodeId;
		int32_t L_30 = *((int32_t*)L_29);
		*((int32_t*)L_28) = (int32_t)L_30;
		int32_t* L_31 = ___0_nodeId;
		int32_t* L_32 = ___0_nodeId;
		int32_t L_33 = *((int32_t*)L_32);
		int32_t L_34;
		L_34 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_35;
		L_35 = RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1(__this, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		*((int32_t*)L_31) = (int32_t)L_35;
	}

IL_0060:
	{
		return (bool)1;
	}

IL_0062:
	{
		return (bool)0;
	}
}
// Method Definition Index: 79464
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	{
		goto IL_000b;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		___0_x_id = L_1;
	}

IL_000b:
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (L_3)
		{
			goto IL_0002;
		}
	}
	{
		int32_t L_4 = ___0_x_id;
		return L_4;
	}
}
// Method Definition Index: 79465
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_2, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_10, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_17, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		RuntimeObject* L_21;
		L_21 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_19, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_26;
		L_26 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_25, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_32 = V_0;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_31, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_33, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_35, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_47, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_61, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 79466
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_2, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_10, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_17, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		RuntimeObject* L_21;
		L_21 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_19, L_21, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_26;
		L_26 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_25, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_28, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_32 = V_0;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_31, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_33, L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_35, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_47, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_61, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 79467
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B54_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		V_0 = 0;
		int32_t L_1 = ___0_root_id;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_2 = ___0_root_id;
		G_B3_0 = L_2;
		goto IL_001c;
	}

IL_0016:
	{
		int32_t L_3 = __this->___root;
		G_B3_0 = L_3;
	}

IL_001c:
	{
		V_1 = G_B3_0;
		int32_t L_4 = __this->____accessMethod;
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_01f8;
		}
	}
	{
		bool L_5 = ___4_append;
		if (L_5)
		{
			goto IL_01f8;
		}
	}
	{
		goto IL_01f0;
	}

IL_0035:
	{
		int32_t L_6 = V_1;
		RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 35));
		int32_t L_7 = V_1;
		V_0 = L_7;
		int32_t L_8 = ___0_root_id;
		if (!L_8)
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_9 = ___1_x_id;
		RuntimeObject* L_10;
		L_10 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_11 = V_1;
		RuntimeObject* L_12;
		L_12 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_13;
		L_13 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(6, __this, L_10, L_12);
		G_B9_0 = L_13;
		goto IL_006b;
	}

IL_0057:
	{
		int32_t L_14 = ___1_x_id;
		RuntimeObject* L_15;
		L_15 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_16 = V_1;
		RuntimeObject* L_17;
		L_17 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_18;
		L_18 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(5, __this, L_15, L_17);
		G_B9_0 = L_18;
	}

IL_006b:
	{
		V_2 = G_B9_0;
		int32_t L_19 = V_2;
		if ((((int32_t)L_19) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_20 = V_1;
		int32_t L_21;
		L_21 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_1 = L_21;
		goto IL_01f0;
	}

IL_007d:
	{
		int32_t L_22 = V_2;
		if ((((int32_t)L_22) <= ((int32_t)0)))
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_23 = V_1;
		int32_t L_24;
		L_24 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_23, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_1 = L_24;
		goto IL_01f0;
	}

IL_008e:
	{
		int32_t L_25 = ___0_root_id;
		if (!L_25)
		{
			goto IL_0098;
		}
	}
	{
		Exception_t* L_26;
		L_26 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_26, method);
	}

IL_0098:
	{
		int32_t L_27 = V_1;
		int32_t L_28;
		L_28 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_28)
		{
			goto IL_00cd;
		}
	}
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_31 = ___1_x_id;
		int32_t L_32 = V_1;
		int32_t L_33;
		L_33 = RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC(__this, L_30, L_31, L_32, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		___0_root_id = L_33;
		int32_t L_34 = V_1;
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		RuntimeObject* L_37;
		L_37 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_34, L_37, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		goto IL_01ee;
	}

IL_00cd:
	{
		V_3 = 0;
		int32_t L_38 = V_1;
		RuntimeObject* L_39;
		L_39 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_38, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_40;
		L_40 = RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73(__this, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_3 = L_40;
		int32_t L_41 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = V_3;
		int32_t L_43 = V_1;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_42, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_44 = V_3;
		int32_t L_45 = V_1;
		int32_t L_46;
		L_46 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_44, L_46, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_47 = V_3;
		int32_t L_48 = V_1;
		int32_t L_49;
		L_49 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_47, L_49, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_50 = V_3;
		int32_t L_51 = V_1;
		int32_t L_52;
		L_52 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_51, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_50, L_52, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_53 = V_3;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_53, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_56 = V_1;
		int32_t L_57;
		L_57 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_58;
		L_58 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_57, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_59 = V_1;
		if ((!(((uint32_t)L_58) == ((uint32_t)L_59))))
		{
			goto IL_014b;
		}
	}
	{
		int32_t L_60 = V_1;
		int32_t L_61;
		L_61 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_62 = V_3;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_61, L_62, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0169;
	}

IL_014b:
	{
		int32_t L_63 = V_1;
		int32_t L_64;
		L_64 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_63, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_65;
		L_65 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_64, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_66 = V_1;
		if ((!(((uint32_t)L_65) == ((uint32_t)L_66))))
		{
			goto IL_0169;
		}
	}
	{
		int32_t L_67 = V_1;
		int32_t L_68;
		L_68 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_67, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_69 = V_3;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_68, L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_0169:
	{
		int32_t L_70 = V_1;
		int32_t L_71;
		L_71 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_70, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_71)
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_72 = V_1;
		int32_t L_73;
		L_73 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_72, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_74 = V_3;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_73, L_74, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0180:
	{
		int32_t L_75 = V_1;
		int32_t L_76;
		L_76 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_75, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_76)
		{
			goto IL_0197;
		}
	}
	{
		int32_t L_77 = V_1;
		int32_t L_78;
		L_78 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_77, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_79 = V_3;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_78, L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0197:
	{
		int32_t L_80 = __this->___root;
		int32_t L_81 = V_1;
		if ((!(((uint32_t)L_80) == ((uint32_t)L_81))))
		{
			goto IL_01a7;
		}
	}
	{
		int32_t L_82 = V_3;
		__this->___root = L_82;
	}

IL_01a7:
	{
		int32_t L_83 = V_1;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_83, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_84 = V_1;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_84, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_85 = V_1;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_85, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_86 = V_1;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_86, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_87 = V_1;
		int32_t L_88;
		L_88 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_87, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_4 = L_88;
		int32_t L_89 = V_1;
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(__this, L_89, 1, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_90 = V_1;
		int32_t L_91 = ___1_x_id;
		int32_t L_92 = V_3;
		int32_t L_93;
		L_93 = RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC(__this, L_90, L_91, L_92, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		___0_root_id = L_93;
		int32_t L_94 = V_3;
		int32_t L_95 = V_4;
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(__this, L_94, L_95, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
	}

IL_01ee:
	{
		int32_t L_96 = ___0_root_id;
		return L_96;
	}

IL_01f0:
	{
		int32_t L_97 = V_1;
		if (L_97)
		{
			goto IL_0035;
		}
	}
	{
		goto IL_0263;
	}

IL_01f8:
	{
		int32_t L_98 = __this->____accessMethod;
		bool L_99 = ___4_append;
		if (!((int32_t)(((((int32_t)L_98) == ((int32_t)2))? 1 : 0)|(int32_t)L_99)))
		{
			goto IL_025b;
		}
	}
	{
		int32_t L_100 = ___3_position;
		if ((!(((uint32_t)L_100) == ((uint32_t)(-1)))))
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_101 = __this->___root;
		int32_t L_102;
		L_102 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_101, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		___3_position = L_102;
		goto IL_0256;
	}

IL_021b:
	{
		int32_t L_103 = V_1;
		RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E(__this, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 35));
		int32_t L_104 = V_1;
		V_0 = L_104;
		int32_t L_105 = ___3_position;
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_108;
		L_108 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_107, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_105, L_108));
		int32_t L_109 = V_5;
		if ((((int32_t)L_109) > ((int32_t)0)))
		{
			goto IL_0245;
		}
	}
	{
		int32_t L_110 = V_1;
		int32_t L_111;
		L_111 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_110, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_1 = L_111;
		goto IL_0256;
	}

IL_0245:
	{
		int32_t L_112 = V_1;
		int32_t L_113;
		L_113 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_112, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_1 = L_113;
		int32_t L_114 = V_1;
		if (!L_114)
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_115 = V_5;
		___3_position = ((int32_t)il2cpp_codegen_subtract(L_115, 1));
	}

IL_0256:
	{
		int32_t L_116 = V_1;
		if (L_116)
		{
			goto IL_021b;
		}
	}
	{
		goto IL_0263;
	}

IL_025b:
	{
		Exception_t* L_117;
		L_117 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)15), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_117, method);
	}

IL_0263:
	{
		int32_t L_118 = ___1_x_id;
		int32_t L_119 = V_0;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_118, L_119, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_120 = V_0;
		if (L_120)
		{
			goto IL_0298;
		}
	}
	{
		int32_t L_121 = ___0_root_id;
		if (L_121)
		{
			goto IL_027d;
		}
	}
	{
		int32_t L_122 = ___1_x_id;
		__this->___root = L_122;
		goto IL_030a;
	}

IL_027d:
	{
		int32_t L_123 = ___2_mainTreeNodeID;
		int32_t L_124 = ___1_x_id;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_123, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_125 = ___2_mainTreeNodeID;
		int32_t L_126 = ___1_x_id;
		RuntimeObject* L_127;
		L_127 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_126, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_125, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_128 = ___1_x_id;
		___0_root_id = L_128;
		goto IL_030a;
	}

IL_0298:
	{
		V_6 = 0;
		int32_t L_129 = __this->____accessMethod;
		if ((!(((uint32_t)L_129) == ((uint32_t)1))))
		{
			goto IL_02d5;
		}
	}
	{
		int32_t L_130 = ___0_root_id;
		if (!L_130)
		{
			goto IL_02bd;
		}
	}
	{
		int32_t L_131 = ___1_x_id;
		RuntimeObject* L_132;
		L_132 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_131, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_133 = V_0;
		RuntimeObject* L_134;
		L_134 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_133, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_135;
		L_135 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(6, __this, L_132, L_134);
		G_B49_0 = L_135;
		goto IL_02d1;
	}

IL_02bd:
	{
		int32_t L_136 = ___1_x_id;
		RuntimeObject* L_137;
		L_137 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_136, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_138 = V_0;
		RuntimeObject* L_139;
		L_139 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_140;
		L_140 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(5, __this, L_137, L_139);
		G_B49_0 = L_140;
	}

IL_02d1:
	{
		V_6 = G_B49_0;
		goto IL_02f3;
	}

IL_02d5:
	{
		int32_t L_141 = __this->____accessMethod;
		if ((!(((uint32_t)L_141) == ((uint32_t)2))))
		{
			goto IL_02eb;
		}
	}
	{
		int32_t L_142 = ___3_position;
		if ((((int32_t)L_142) <= ((int32_t)0)))
		{
			goto IL_02e6;
		}
	}
	{
		G_B54_0 = 1;
		goto IL_02e7;
	}

IL_02e6:
	{
		G_B54_0 = (-1);
	}

IL_02e7:
	{
		V_6 = G_B54_0;
		goto IL_02f3;
	}

IL_02eb:
	{
		Exception_t* L_143;
		L_143 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)16), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_143, method);
	}

IL_02f3:
	{
		int32_t L_144 = V_6;
		if ((((int32_t)L_144) >= ((int32_t)0)))
		{
			goto IL_0302;
		}
	}
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___1_x_id;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_145, L_146, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_030a;
	}

IL_0302:
	{
		int32_t L_147 = V_0;
		int32_t L_148 = ___1_x_id;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_147, L_148, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_030a:
	{
		int32_t L_149 = ___1_x_id;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_149, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_150 = ___1_x_id;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_150, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_151 = ___1_x_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_151, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_152 = ___1_x_id;
		V_1 = L_152;
		goto IL_04ba;
	}

IL_0329:
	{
		int32_t L_153 = ___1_x_id;
		int32_t L_154;
		L_154 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_153, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_155 = ___1_x_id;
		int32_t L_156;
		L_156 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_155, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_157;
		L_157 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_156, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_158;
		L_158 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_157, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_154) == ((uint32_t)L_158))))
		{
			goto IL_0405;
		}
	}
	{
		int32_t L_159 = ___1_x_id;
		int32_t L_160;
		L_160 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_159, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_161;
		L_161 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_160, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_162;
		L_162 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_161, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_162;
		int32_t L_163 = V_0;
		int32_t L_164;
		L_164 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_163, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_164)
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_165 = ___1_x_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_165, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_166, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_167 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_167, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_168 = ___1_x_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_168, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_170;
		L_170 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_169, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_170, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_171 = ___1_x_id;
		int32_t L_172;
		L_172 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_171, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_173;
		L_173 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_172, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_173;
		goto IL_04ba;
	}

IL_03a3:
	{
		int32_t L_174 = ___1_x_id;
		int32_t L_175 = ___1_x_id;
		int32_t L_176;
		L_176 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_175, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_177;
		L_177 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_176, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_174) == ((uint32_t)L_177))))
		{
			goto IL_03c7;
		}
	}
	{
		int32_t L_178 = ___1_x_id;
		int32_t L_179;
		L_179 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_178, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_179;
		int32_t L_180 = ___0_root_id;
		int32_t L_181 = ___1_x_id;
		int32_t L_182 = ___2_mainTreeNodeID;
		int32_t L_183;
		L_183 = RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3(__this, L_180, L_181, L_182, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_183;
	}

IL_03c7:
	{
		int32_t L_184 = ___1_x_id;
		int32_t L_185;
		L_185 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_184, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_185, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_186 = ___1_x_id;
		int32_t L_187;
		L_187 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_186, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_188;
		L_188 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_187, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_188, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_189 = ___0_root_id;
		int32_t L_190 = ___1_x_id;
		int32_t L_191;
		L_191 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_190, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_192;
		L_192 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_191, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_193 = ___2_mainTreeNodeID;
		int32_t L_194;
		L_194 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_189, L_192, L_193, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_194;
		goto IL_04ba;
	}

IL_0405:
	{
		int32_t L_195 = ___1_x_id;
		int32_t L_196;
		L_196 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_195, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_197;
		L_197 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_196, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_198;
		L_198 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_197, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_198;
		int32_t L_199 = V_0;
		int32_t L_200;
		L_200 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_199, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_200)
		{
			goto IL_045d;
		}
	}
	{
		int32_t L_201 = ___1_x_id;
		int32_t L_202;
		L_202 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_201, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_202, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_203 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_203, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_204 = ___1_x_id;
		int32_t L_205;
		L_205 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_204, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_206;
		L_206 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_205, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_206, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_207 = ___1_x_id;
		int32_t L_208;
		L_208 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_207, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_209;
		L_209 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_208, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_209;
		goto IL_04ba;
	}

IL_045d:
	{
		int32_t L_210 = ___1_x_id;
		int32_t L_211 = ___1_x_id;
		int32_t L_212;
		L_212 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_211, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_213;
		L_213 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_212, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_210) == ((uint32_t)L_213))))
		{
			goto IL_0481;
		}
	}
	{
		int32_t L_214 = ___1_x_id;
		int32_t L_215;
		L_215 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_214, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___1_x_id = L_215;
		int32_t L_216 = ___0_root_id;
		int32_t L_217 = ___1_x_id;
		int32_t L_218 = ___2_mainTreeNodeID;
		int32_t L_219;
		L_219 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_216, L_217, L_218, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_219;
	}

IL_0481:
	{
		int32_t L_220 = ___1_x_id;
		int32_t L_221;
		L_221 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_220, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_221, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_222 = ___1_x_id;
		int32_t L_223;
		L_223 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_222, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_224;
		L_224 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_223, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_224, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_225 = ___0_root_id;
		int32_t L_226 = ___1_x_id;
		int32_t L_227;
		L_227 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_226, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_228;
		L_228 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_227, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_229 = ___2_mainTreeNodeID;
		int32_t L_230;
		L_230 = RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3(__this, L_225, L_228, L_229, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_230;
	}

IL_04ba:
	{
		int32_t L_231 = ___1_x_id;
		int32_t L_232;
		L_232 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_231, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_233;
		L_233 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_232, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (!L_233)
		{
			goto IL_0329;
		}
	}
	{
		int32_t L_234 = ___0_root_id;
		if (L_234)
		{
			goto IL_04de;
		}
	}
	{
		int32_t L_235 = __this->___root;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_235, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		goto IL_04e6;
	}

IL_04de:
	{
		int32_t L_236 = ___0_root_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_236, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
	}

IL_04e6:
	{
		int32_t L_237 = ___0_root_id;
		return L_237;
	}
}
// Method Definition Index: 79468
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_UpdateNodeKey_m1D17263A43DA1E8A0CDCFFE7513A207930104402_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_currentKey, RuntimeObject* ___1_newKey, const RuntimeMethod* method) 
{
	NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_currentKey;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_0 = L_1;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (L_4)
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		int32_t L_7 = __this->___root;
		if ((((int32_t)L_6) == ((int32_t)L_7)))
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_8 = V_0;
		int32_t L_9 = L_8.____mainTreeNodeID;
		RuntimeObject* L_10 = ___1_newKey;
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_9, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_0031:
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_11 = V_0;
		int32_t L_12 = L_11.____nodeID;
		RuntimeObject* L_13 = ___1_newKey;
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_12, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		return;
	}
}
// Method Definition Index: 79469
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_DeleteByIndex_m77EB3F96268C89DEA1218BA5DB3CB1A8EEC073F6_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_i, const RuntimeMethod* method) 
{
	NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_i;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		V_0 = L_1;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		RuntimeObject* L_4;
		L_4 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_7 = V_0;
		int32_t L_8 = L_7.____mainTreeNodeID;
		int32_t L_9;
		L_9 = RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C(__this, 0, L_6, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_4;
	}
}
// Method Definition Index: 79470
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDelete_m6F0CAA42CFE58D5FFBBC866711871E2528CE5AD2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_z_id, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_z_id;
		int32_t L_1;
		L_1 = RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C(__this, 0, L_0, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_1;
	}
}
// Method Definition Index: 79471
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t G_B5_0 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___1_z_id;
		int32_t L_1;
		L_1 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_1)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = ___1_z_id;
		int32_t L_3;
		L_3 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_4 = ___1_z_id;
		int32_t L_5;
		L_5 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_6 = ___1_z_id;
		int32_t L_7;
		L_7 = RBTree_1_RBDeleteX_m61010CD7CB4B2C5EA027848024A26D252CCE530C(__this, L_3, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 47));
		return L_7;
	}

IL_0021:
	{
		V_3 = (bool)0;
		int32_t L_8 = __this->____accessMethod;
		if ((((int32_t)L_8) == ((int32_t)1)))
		{
			goto IL_002f;
		}
	}
	{
		int32_t L_9 = ___1_z_id;
		G_B5_0 = L_9;
		goto IL_0030;
	}

IL_002f:
	{
		int32_t L_10 = ___2_mainTreeNodeID;
		G_B5_0 = L_10;
	}

IL_0030:
	{
		V_4 = G_B5_0;
		int32_t L_11 = V_4;
		int32_t L_12;
		L_12 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_12)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_13 = V_4;
		int32_t L_14;
		L_14 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		___0_root_id = L_14;
	}

IL_0046:
	{
		int32_t L_15 = V_4;
		int32_t L_16;
		L_16 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_17;
		L_17 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((!(((uint32_t)L_17) == ((uint32_t)2))))
		{
			goto IL_005b;
		}
	}
	{
		V_3 = (bool)1;
		goto IL_0073;
	}

IL_005b:
	{
		int32_t L_18 = V_4;
		int32_t L_19;
		L_19 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_20;
		L_20 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((!(((uint32_t)L_20) == ((uint32_t)1))))
		{
			goto IL_0073;
		}
	}
	{
		Exception_t* L_21;
		L_21 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)7, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_21, method);
	}

IL_0073:
	{
		int32_t L_22 = ___1_z_id;
		int32_t L_23;
		L_23 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_23)
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_24 = ___1_z_id;
		int32_t L_25;
		L_25 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (L_25)
		{
			goto IL_0089;
		}
	}

IL_0085:
	{
		int32_t L_26 = ___1_z_id;
		V_1 = L_26;
		goto IL_0091;
	}

IL_0089:
	{
		int32_t L_27 = ___1_z_id;
		int32_t L_28;
		L_28 = RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_28;
	}

IL_0091:
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_30)
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_31 = V_1;
		int32_t L_32;
		L_32 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_31, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_32;
		goto IL_00ac;
	}

IL_00a4:
	{
		int32_t L_33 = V_1;
		int32_t L_34;
		L_34 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_34;
	}

IL_00ac:
	{
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_2 = L_36;
		int32_t L_37 = V_0;
		if (!L_37)
		{
			goto IL_00bf;
		}
	}
	{
		int32_t L_38 = V_0;
		int32_t L_39 = V_2;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_38, L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_00bf:
	{
		int32_t L_40 = V_2;
		if (L_40)
		{
			goto IL_00d3;
		}
	}
	{
		int32_t L_41 = ___0_root_id;
		if (L_41)
		{
			goto IL_00ce;
		}
	}
	{
		int32_t L_42 = V_0;
		__this->___root = L_42;
		goto IL_00ef;
	}

IL_00ce:
	{
		int32_t L_43 = V_0;
		___0_root_id = L_43;
		goto IL_00ef;
	}

IL_00d3:
	{
		int32_t L_44 = V_1;
		int32_t L_45 = V_2;
		int32_t L_46;
		L_46 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((!(((uint32_t)L_44) == ((uint32_t)L_46))))
		{
			goto IL_00e7;
		}
	}
	{
		int32_t L_47 = V_2;
		int32_t L_48 = V_0;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_47, L_48, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_00ef;
	}

IL_00e7:
	{
		int32_t L_49 = V_2;
		int32_t L_50 = V_0;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_49, L_50, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_00ef:
	{
		int32_t L_51 = V_1;
		int32_t L_52 = ___1_z_id;
		if ((((int32_t)L_51) == ((int32_t)L_52)))
		{
			goto IL_010f;
		}
	}
	{
		int32_t L_53 = ___1_z_id;
		int32_t L_54 = V_1;
		RuntimeObject* L_55;
		L_55 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_53, L_55, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
		int32_t L_56 = ___1_z_id;
		int32_t L_57 = V_1;
		int32_t L_58;
		L_58 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_57, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_56, L_58, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
	}

IL_010f:
	{
		int32_t L_59 = V_4;
		int32_t L_60;
		L_60 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_60)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_61 = ___0_root_id;
		if (L_61)
		{
			goto IL_0128;
		}
	}
	{
		int32_t L_62 = ___1_z_id;
		int32_t L_63 = V_4;
		if ((((int32_t)L_62) == ((int32_t)L_63)))
		{
			goto IL_0128;
		}
	}
	{
		Exception_t* L_64;
		L_64 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_64, method);
	}

IL_0128:
	{
		int32_t L_65 = ___0_root_id;
		if (!L_65)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_66 = V_4;
		int32_t L_67 = ___0_root_id;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_66, L_67, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_68 = V_4;
		int32_t L_69 = ___0_root_id;
		RuntimeObject* L_70;
		L_70 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_68, L_70, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_0143:
	{
		int32_t L_71 = V_2;
		V_5 = L_71;
		goto IL_015a;
	}

IL_0148:
	{
		int32_t L_72 = V_5;
		RBTree_1_RecomputeSize_m5B049EA2694E6343E2D30EDCDB34CC4C44A0FD08(__this, L_72, il2cpp_rgctx_method(method->klass->rgctx_data, 48));
		int32_t L_73 = V_5;
		int32_t L_74;
		L_74 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_73, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_5 = L_74;
	}

IL_015a:
	{
		int32_t L_75 = V_5;
		if (L_75)
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_76 = ___0_root_id;
		if (!L_76)
		{
			goto IL_017d;
		}
	}
	{
		int32_t L_77 = V_4;
		V_6 = L_77;
		goto IL_0179;
	}

IL_0167:
	{
		int32_t L_78 = V_6;
		RBTree_1_DecreaseSize_m63463D3F02F9E581B66DAC4F5311669F2284C603(__this, L_78, il2cpp_rgctx_method(method->klass->rgctx_data, 49));
		int32_t L_79 = V_6;
		int32_t L_80;
		L_80 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_6 = L_80;
	}

IL_0179:
	{
		int32_t L_81 = V_6;
		if (L_81)
		{
			goto IL_0167;
		}
	}

IL_017d:
	{
		int32_t L_82 = V_1;
		int32_t L_83;
		L_83 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_82, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_83) == ((uint32_t)1))))
		{
			goto IL_0193;
		}
	}
	{
		int32_t L_84 = ___0_root_id;
		int32_t L_85 = V_0;
		int32_t L_86 = V_2;
		int32_t L_87 = ___2_mainTreeNodeID;
		int32_t L_88;
		L_88 = RBTree_1_RBDeleteFixup_m7FD4570F1436DF16B372F9317522C5D1CDB8B597(__this, L_84, L_85, L_86, L_87, il2cpp_rgctx_method(method->klass->rgctx_data, 50));
		___0_root_id = L_88;
	}

IL_0193:
	{
		bool L_89 = V_3;
		if (!L_89)
		{
			goto IL_02af;
		}
	}
	{
		int32_t L_90 = V_4;
		if (!L_90)
		{
			goto IL_01ae;
		}
	}
	{
		int32_t L_91 = V_4;
		int32_t L_92;
		L_92 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_91, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_93;
		L_93 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_92, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((((int32_t)L_93) == ((int32_t)1)))
		{
			goto IL_01b6;
		}
	}

IL_01ae:
	{
		Exception_t* L_94;
		L_94 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)9), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_94, method);
	}

IL_01b6:
	{
		int32_t L_95 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_subtract(L_95, 1));
		int32_t L_96 = V_4;
		int32_t L_97;
		L_97 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_96, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		V_7 = L_97;
		int32_t L_98 = V_7;
		int32_t L_99 = V_4;
		int32_t L_100;
		L_100 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_99, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_98, L_100, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_101 = V_7;
		int32_t L_102 = V_4;
		int32_t L_103;
		L_103 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_102, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_101, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_104 = V_7;
		int32_t L_105 = V_4;
		int32_t L_106;
		L_106 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_105, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(__this, L_104, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_107 = V_7;
		int32_t L_108 = V_4;
		int32_t L_109;
		L_109 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_108, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_107, L_109, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_110 = V_4;
		int32_t L_111;
		L_111 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_110, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (!L_111)
		{
			goto IL_025c;
		}
	}
	{
		int32_t L_112 = V_7;
		int32_t L_113 = V_4;
		int32_t L_114;
		L_114 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_113, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_112, L_114, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_115 = V_4;
		int32_t L_116;
		L_116 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_115, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_117;
		L_117 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_116, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_118 = V_4;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_118))))
		{
			goto IL_024c;
		}
	}
	{
		int32_t L_119 = V_4;
		int32_t L_120;
		L_120 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_119, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_121 = V_7;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_120, L_121, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_025c;
	}

IL_024c:
	{
		int32_t L_122 = V_4;
		int32_t L_123;
		L_123 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_122, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_124 = V_7;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_123, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_025c:
	{
		int32_t L_125 = V_4;
		int32_t L_126;
		L_126 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_125, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_126)
		{
			goto IL_0276;
		}
	}
	{
		int32_t L_127 = V_4;
		int32_t L_128;
		L_128 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_129 = V_7;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_128, L_129, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0276:
	{
		int32_t L_130 = V_4;
		int32_t L_131;
		L_131 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_130, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_131)
		{
			goto IL_0290;
		}
	}
	{
		int32_t L_132 = V_4;
		int32_t L_133;
		L_133 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_132, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_134 = V_7;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_133, L_134, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0290:
	{
		int32_t L_135 = __this->___root;
		int32_t L_136 = V_4;
		if ((!(((uint32_t)L_135) == ((uint32_t)L_136))))
		{
			goto IL_02a2;
		}
	}
	{
		int32_t L_137 = V_7;
		__this->___root = L_137;
	}

IL_02a2:
	{
		int32_t L_138 = V_4;
		RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8(__this, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
		V_4 = 0;
		goto IL_02e4;
	}

IL_02af:
	{
		int32_t L_139 = V_4;
		int32_t L_140;
		L_140 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_139, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_140)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		if (L_141)
		{
			goto IL_02c9;
		}
	}
	{
		int32_t L_142 = ___1_z_id;
		int32_t L_143 = V_4;
		if ((((int32_t)L_142) == ((int32_t)L_143)))
		{
			goto IL_02c9;
		}
	}
	{
		Exception_t* L_144;
		L_144 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)10), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_144, method);
	}

IL_02c9:
	{
		int32_t L_145 = ___0_root_id;
		if (!L_145)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_146 = V_4;
		int32_t L_147 = ___0_root_id;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_146, L_147, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
		int32_t L_148 = V_4;
		int32_t L_149 = ___0_root_id;
		RuntimeObject* L_150;
		L_150 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_149, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9(__this, L_148, L_150, il2cpp_rgctx_method(method->klass->rgctx_data, 31));
	}

IL_02e4:
	{
		int32_t L_151 = V_1;
		int32_t L_152 = ___1_z_id;
		if ((((int32_t)L_151) == ((int32_t)L_152)))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_153 = V_1;
		int32_t L_154 = ___1_z_id;
		int32_t L_155;
		L_155 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_154, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_153, L_155, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		int32_t L_156 = V_1;
		int32_t L_157 = ___1_z_id;
		int32_t L_158;
		L_158 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_157, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_156, L_158, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		int32_t L_159 = V_1;
		int32_t L_160 = ___1_z_id;
		int32_t L_161;
		L_161 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_160, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_159, L_161, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_162 = V_1;
		int32_t L_163 = ___1_z_id;
		int32_t L_164;
		L_164 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_163, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD(__this, L_162, L_164, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		int32_t L_165 = ___1_z_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_165, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		if (!L_166)
		{
			goto IL_036a;
		}
	}
	{
		int32_t L_167 = V_1;
		int32_t L_168 = ___1_z_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_168, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_167, L_169, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
		int32_t L_170 = ___1_z_id;
		int32_t L_171;
		L_171 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_170, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_172;
		L_172 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_171, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_173 = ___1_z_id;
		if ((!(((uint32_t)L_172) == ((uint32_t)L_173))))
		{
			goto IL_035a;
		}
	}
	{
		int32_t L_174 = ___1_z_id;
		int32_t L_175;
		L_175 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_174, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_176 = V_1;
		RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052(__this, L_175, L_176, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		goto IL_0372;
	}

IL_035a:
	{
		int32_t L_177 = ___1_z_id;
		int32_t L_178;
		L_178 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_177, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_179 = V_1;
		RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4(__this, L_178, L_179, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
		goto IL_0372;
	}

IL_036a:
	{
		int32_t L_180 = V_1;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_180, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0372:
	{
		int32_t L_181 = ___1_z_id;
		int32_t L_182;
		L_182 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_181, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (!L_182)
		{
			goto IL_0389;
		}
	}
	{
		int32_t L_183 = ___1_z_id;
		int32_t L_184;
		L_184 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_183, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_185 = V_1;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_184, L_185, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_0389:
	{
		int32_t L_186 = ___1_z_id;
		int32_t L_187;
		L_187 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_186, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if (!L_187)
		{
			goto IL_03a0;
		}
	}
	{
		int32_t L_188 = ___1_z_id;
		int32_t L_189;
		L_189 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_188, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_190 = V_1;
		RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493(__this, L_189, L_190, il2cpp_rgctx_method(method->klass->rgctx_data, 28));
	}

IL_03a0:
	{
		int32_t L_191 = __this->___root;
		int32_t L_192 = ___1_z_id;
		if ((!(((uint32_t)L_191) == ((uint32_t)L_192))))
		{
			goto IL_03b2;
		}
	}
	{
		int32_t L_193 = V_1;
		__this->___root = L_193;
		goto IL_03b9;
	}

IL_03b2:
	{
		int32_t L_194 = ___0_root_id;
		int32_t L_195 = ___1_z_id;
		if ((!(((uint32_t)L_194) == ((uint32_t)L_195))))
		{
			goto IL_03b9;
		}
	}
	{
		int32_t L_196 = V_1;
		___0_root_id = L_196;
	}

IL_03b9:
	{
		int32_t L_197 = V_4;
		if (!L_197)
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_198 = V_4;
		int32_t L_199;
		L_199 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_198, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_200 = ___1_z_id;
		if ((!(((uint32_t)L_199) == ((uint32_t)L_200))))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_201 = V_4;
		int32_t L_202 = V_1;
		RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8(__this, L_201, L_202, il2cpp_rgctx_method(method->klass->rgctx_data, 29));
	}

IL_03d1:
	{
		int32_t L_203 = ___1_z_id;
		RBTree_1_FreeNode_m2284FBA53D1081B794CEC801EE442A646B7C0AA8(__this, L_203, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
		int32_t L_204 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_204, 1));
		int32_t L_205 = ___1_z_id;
		return L_205;
	}
}
// Method Definition Index: 79472
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m7FD4570F1436DF16B372F9317522C5D1CDB8B597_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B24_0 = 0;
	int32_t G_B28_0 = 0;
	int32_t G_B34_0 = 0;
	int32_t G_B38_0 = 0;
	int32_t G_B47_0 = 0;
	int32_t G_B52_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B60_0 = 0;
	{
		int32_t L_0 = ___1_x_id;
		if (L_0)
		{
			goto IL_0305;
		}
	}
	{
		int32_t L_1 = ___2_px_id;
		if (L_1)
		{
			goto IL_0305;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		int32_t L_2 = ___1_x_id;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_3 = ___1_x_id;
		int32_t L_4 = ___1_x_id;
		int32_t L_5;
		L_5 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_6;
		L_6 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if ((((int32_t)L_3) == ((int32_t)L_6)))
		{
			goto IL_0033;
		}
	}

IL_0021:
	{
		int32_t L_7 = ___1_x_id;
		if (L_7)
		{
			goto IL_0168;
		}
	}
	{
		int32_t L_8 = ___2_px_id;
		int32_t L_9;
		L_9 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		if (L_9)
		{
			goto IL_0168;
		}
	}

IL_0033:
	{
		int32_t L_10 = ___1_x_id;
		if (!L_10)
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_13;
		L_13 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B10_0 = L_13;
		goto IL_004c;
	}

IL_0045:
	{
		int32_t L_14 = ___2_px_id;
		int32_t L_15;
		L_15 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B10_0 = L_15;
	}

IL_004c:
	{
		V_0 = G_B10_0;
		int32_t L_16 = V_0;
		if (L_16)
		{
			goto IL_0058;
		}
	}
	{
		Exception_t* L_17;
		L_17 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)14), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_0058:
	{
		int32_t L_18 = V_0;
		int32_t L_19;
		L_19 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_18, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_19)
		{
			goto IL_0097;
		}
	}
	{
		int32_t L_20 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_20, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_21 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_21, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_22 = ___0_root_id;
		int32_t L_23 = ___2_px_id;
		int32_t L_24 = ___3_mainTreeNodeID;
		int32_t L_25;
		L_25 = RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3(__this, L_22, L_23, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_25;
		int32_t L_26 = ___1_x_id;
		if (!L_26)
		{
			goto IL_008f;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_27, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_29;
		L_29 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_28, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B16_0 = L_29;
		goto IL_0096;
	}

IL_008f:
	{
		int32_t L_30 = ___2_px_id;
		int32_t L_31;
		L_31 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B16_0 = L_31;
	}

IL_0096:
	{
		V_0 = G_B16_0;
	}

IL_0097:
	{
		int32_t L_32 = V_0;
		int32_t L_33;
		L_33 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_32, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_34;
		L_34 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_34) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_35 = V_0;
		int32_t L_36;
		L_36 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_35, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_37;
		L_37 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_37) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_38 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_38, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_39 = ___2_px_id;
		___1_x_id = L_39;
		int32_t L_40 = ___2_px_id;
		int32_t L_41;
		L_41 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_40, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_41;
		goto IL_0305;
	}

IL_00d0:
	{
		int32_t L_42 = V_0;
		int32_t L_43;
		L_43 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_42, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_44;
		L_44 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_43, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_44) == ((uint32_t)1))))
		{
			goto IL_011c;
		}
	}
	{
		int32_t L_45 = V_0;
		int32_t L_46;
		L_46 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_46, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_47 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_47, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_48 = ___0_root_id;
		int32_t L_49 = V_0;
		int32_t L_50 = ___3_mainTreeNodeID;
		int32_t L_51;
		L_51 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_48, L_49, L_50, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_51;
		int32_t L_52 = ___1_x_id;
		if (!L_52)
		{
			goto IL_0114;
		}
	}
	{
		int32_t L_53 = ___1_x_id;
		int32_t L_54;
		L_54 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_53, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_55;
		L_55 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_54, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B24_0 = L_55;
		goto IL_011b;
	}

IL_0114:
	{
		int32_t L_56 = ___2_px_id;
		int32_t L_57;
		L_57 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_56, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		G_B24_0 = L_57;
	}

IL_011b:
	{
		V_0 = G_B24_0;
	}

IL_011c:
	{
		int32_t L_58 = V_0;
		int32_t L_59 = ___2_px_id;
		int32_t L_60;
		L_60 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_58, L_60, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_61 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_61, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_62 = V_0;
		int32_t L_63;
		L_63 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_62, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_63, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_64 = ___0_root_id;
		int32_t L_65 = ___2_px_id;
		int32_t L_66 = ___3_mainTreeNodeID;
		int32_t L_67;
		L_67 = RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3(__this, L_64, L_65, L_66, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_67;
		int32_t L_68 = ___0_root_id;
		if (!L_68)
		{
			goto IL_0152;
		}
	}
	{
		int32_t L_69 = ___0_root_id;
		G_B28_0 = L_69;
		goto IL_0158;
	}

IL_0152:
	{
		int32_t L_70 = __this->___root;
		G_B28_0 = L_70;
	}

IL_0158:
	{
		___1_x_id = G_B28_0;
		int32_t L_71 = ___1_x_id;
		int32_t L_72;
		L_72 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_71, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_72;
		goto IL_0305;
	}

IL_0168:
	{
		int32_t L_73 = ___2_px_id;
		int32_t L_74;
		L_74 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_73, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_74;
		int32_t L_75 = V_0;
		int32_t L_76;
		L_76 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_75, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if (L_76)
		{
			goto IL_01ed;
		}
	}
	{
		int32_t L_77 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_77, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_78 = ___1_x_id;
		if (!L_78)
		{
			goto IL_01b4;
		}
	}
	{
		int32_t L_79 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_79, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_80 = ___0_root_id;
		int32_t L_81 = ___2_px_id;
		int32_t L_82 = ___3_mainTreeNodeID;
		int32_t L_83;
		L_83 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_80, L_81, L_82, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_83;
		int32_t L_84 = ___1_x_id;
		if (!L_84)
		{
			goto IL_01aa;
		}
	}
	{
		int32_t L_85 = ___1_x_id;
		int32_t L_86;
		L_86 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_85, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_87;
		L_87 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_86, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B34_0 = L_87;
		goto IL_01b1;
	}

IL_01aa:
	{
		int32_t L_88 = ___2_px_id;
		int32_t L_89;
		L_89 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_88, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B34_0 = L_89;
	}

IL_01b1:
	{
		V_0 = G_B34_0;
		goto IL_01ed;
	}

IL_01b4:
	{
		int32_t L_90 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_90, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_91 = ___0_root_id;
		int32_t L_92 = ___2_px_id;
		int32_t L_93 = ___3_mainTreeNodeID;
		int32_t L_94;
		L_94 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_91, L_92, L_93, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_94;
		int32_t L_95 = ___1_x_id;
		if (!L_95)
		{
			goto IL_01da;
		}
	}
	{
		int32_t L_96 = ___1_x_id;
		int32_t L_97;
		L_97 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_96, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_98;
		L_98 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_97, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B38_0 = L_98;
		goto IL_01e1;
	}

IL_01da:
	{
		int32_t L_99 = ___2_px_id;
		int32_t L_100;
		L_100 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_99, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B38_0 = L_100;
	}

IL_01e1:
	{
		V_0 = G_B38_0;
		int32_t L_101 = V_0;
		if (L_101)
		{
			goto IL_01ed;
		}
	}
	{
		Exception_t* L_102;
		L_102 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)11), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_102, method);
	}

IL_01ed:
	{
		int32_t L_103 = V_0;
		int32_t L_104;
		L_104 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_103, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_105;
		L_105 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_104, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_105) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_106, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_108;
		L_108 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_107, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_108) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_109 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_109, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_110 = ___2_px_id;
		___1_x_id = L_110;
		int32_t L_111 = ___2_px_id;
		int32_t L_112;
		L_112 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_111, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_112;
		goto IL_0305;
	}

IL_0226:
	{
		int32_t L_113 = V_0;
		int32_t L_114;
		L_114 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_113, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_115;
		L_115 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_114, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((!(((uint32_t)L_115) == ((uint32_t)1))))
		{
			goto IL_0272;
		}
	}
	{
		int32_t L_116 = V_0;
		int32_t L_117;
		L_117 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_116, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_117, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_118 = V_0;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_118, (int32_t)0, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_119 = ___0_root_id;
		int32_t L_120 = V_0;
		int32_t L_121 = ___3_mainTreeNodeID;
		int32_t L_122;
		L_122 = RBTree_1_LeftRotate_m6FAEDAE5FEA845BB51C6E52F7F3797987043F8A3(__this, L_119, L_120, L_121, il2cpp_rgctx_method(method->klass->rgctx_data, 42));
		___0_root_id = L_122;
		int32_t L_123 = ___1_x_id;
		if (!L_123)
		{
			goto IL_026a;
		}
	}
	{
		int32_t L_124 = ___1_x_id;
		int32_t L_125;
		L_125 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_124, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		int32_t L_126;
		L_126 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_125, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B47_0 = L_126;
		goto IL_0271;
	}

IL_026a:
	{
		int32_t L_127 = ___2_px_id;
		int32_t L_128;
		L_128 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_127, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		G_B47_0 = L_128;
	}

IL_0271:
	{
		V_0 = G_B47_0;
	}

IL_0272:
	{
		int32_t L_129 = ___1_x_id;
		if (!L_129)
		{
			goto IL_02be;
		}
	}
	{
		int32_t L_130 = V_0;
		int32_t L_131 = ___2_px_id;
		int32_t L_132;
		L_132 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_131, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_130, L_132, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_133 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_133, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_134 = V_0;
		int32_t L_135;
		L_135 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_134, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_135, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_136 = ___0_root_id;
		int32_t L_137 = ___2_px_id;
		int32_t L_138 = ___3_mainTreeNodeID;
		int32_t L_139;
		L_139 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_136, L_137, L_138, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_139;
		int32_t L_140 = ___0_root_id;
		if (!L_140)
		{
			goto IL_02ab;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		G_B52_0 = L_141;
		goto IL_02b1;
	}

IL_02ab:
	{
		int32_t L_142 = __this->___root;
		G_B52_0 = L_142;
	}

IL_02b1:
	{
		___1_x_id = G_B52_0;
		int32_t L_143 = ___1_x_id;
		int32_t L_144;
		L_144 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_143, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_144;
		goto IL_0305;
	}

IL_02be:
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___2_px_id;
		int32_t L_147;
		L_147 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_146, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_145, L_147, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_148 = ___2_px_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_148, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_149 = V_0;
		int32_t L_150;
		L_150 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_149, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_150, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_151 = ___0_root_id;
		int32_t L_152 = ___2_px_id;
		int32_t L_153 = ___3_mainTreeNodeID;
		int32_t L_154;
		L_154 = RBTree_1_RightRotate_m2A33BBCDE144E00B7E1C6C1A17ECF008E2A5660C(__this, L_151, L_152, L_153, il2cpp_rgctx_method(method->klass->rgctx_data, 43));
		___0_root_id = L_154;
		int32_t L_155 = ___0_root_id;
		if (!L_155)
		{
			goto IL_02f4;
		}
	}
	{
		int32_t L_156 = ___0_root_id;
		G_B56_0 = L_156;
		goto IL_02fa;
	}

IL_02f4:
	{
		int32_t L_157 = __this->___root;
		G_B56_0 = L_157;
	}

IL_02fa:
	{
		___1_x_id = G_B56_0;
		int32_t L_158 = ___1_x_id;
		int32_t L_159;
		L_159 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_158, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		___2_px_id = L_159;
	}

IL_0305:
	{
		int32_t L_160 = ___0_root_id;
		if (!L_160)
		{
			goto IL_030b;
		}
	}
	{
		int32_t L_161 = ___0_root_id;
		G_B60_0 = L_161;
		goto IL_0311;
	}

IL_030b:
	{
		int32_t L_162 = __this->___root;
		G_B60_0 = L_162;
	}

IL_0311:
	{
		int32_t L_163 = ___1_x_id;
		if ((((int32_t)G_B60_0) == ((int32_t)L_163)))
		{
			goto IL_0321;
		}
	}
	{
		int32_t L_164 = ___1_x_id;
		int32_t L_165;
		L_165 = RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1(__this, L_164, il2cpp_rgctx_method(method->klass->rgctx_data, 40));
		if ((((int32_t)L_165) == ((int32_t)1)))
		{
			goto IL_000e;
		}
	}

IL_0321:
	{
		int32_t L_166 = ___1_x_id;
		RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2(__this, L_166, (int32_t)1, il2cpp_rgctx_method(method->klass->rgctx_data, 41));
		int32_t L_167 = ___0_root_id;
		return L_167;
	}
}
// Method Definition Index: 79473
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_root_id, RuntimeObject* ___1_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B10_0 = 0;
	{
		int32_t L_0 = ___0_root_id;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_1 = __this->____accessMethod;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0014;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)17), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_root_id;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_4 = ___0_root_id;
		G_B6_0 = L_4;
		goto IL_0020;
	}

IL_001a:
	{
		int32_t L_5 = __this->___root;
		G_B6_0 = L_5;
	}

IL_0020:
	{
		V_0 = G_B6_0;
		goto IL_005e;
	}

IL_0023:
	{
		int32_t L_6 = ___0_root_id;
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		RuntimeObject* L_7 = ___1_key;
		int32_t L_8 = V_0;
		RuntimeObject* L_9;
		L_9 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_10;
		L_10 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(6, __this, L_7, L_9);
		G_B10_0 = L_10;
		goto IL_0044;
	}

IL_0036:
	{
		RuntimeObject* L_11 = ___1_key;
		int32_t L_12 = V_0;
		RuntimeObject* L_13;
		L_13 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_14;
		L_14 = VirtualFuncInvoker2< int32_t, RuntimeObject*, RuntimeObject* >::Invoke(5, __this, L_11, L_13);
		G_B10_0 = L_14;
	}

IL_0044:
	{
		V_1 = G_B10_0;
		int32_t L_15 = V_1;
		if (!L_15)
		{
			goto IL_0061;
		}
	}
	{
		int32_t L_16 = V_1;
		if ((((int32_t)L_16) >= ((int32_t)0)))
		{
			goto IL_0056;
		}
	}
	{
		int32_t L_17 = V_0;
		int32_t L_18;
		L_18 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_17, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_18;
		goto IL_005e;
	}

IL_0056:
	{
		int32_t L_19 = V_0;
		int32_t L_20;
		L_20 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_20;
	}

IL_005e:
	{
		int32_t L_21 = V_0;
		if (L_21)
		{
			goto IL_0023;
		}
	}

IL_0061:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 79474
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_get_Item_m32AD1E01917C63769D37170692790A4A3A7C2EF9_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		int32_t L_2 = L_1.____nodeID;
		RuntimeObject* L_3;
		L_3 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		return L_3;
	}
}
// Method Definition Index: 79475
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_key;
		int32_t L_1;
		L_1 = RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549(__this, 0, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_3)
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		RuntimeObject* L_6 = ___0_key;
		int32_t L_7;
		L_7 = RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549(__this, L_5, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		int32_t L_8 = V_0;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_9;
		memset((&L_9), 0, sizeof(L_9));
		NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45((&L_9), L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_9;
	}

IL_0027:
	{
		int32_t L_10 = V_0;
		RuntimeObject* L_11;
		L_11 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		V_1 = L_11;
		RuntimeObject* L_12 = ___0_key;
		NullCheck((V_1));
		bool L_13;
		L_13 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, (V_1), L_12);
		if (L_13)
		{
			goto IL_0046;
		}
	}
	{
		V_0 = 0;
	}

IL_0046:
	{
		int32_t L_14 = V_0;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_15;
		memset((&L_15), 0, sizeof(L_15));
		NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45((&L_15), L_14, 0, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_15;
	}
}
// Method Definition Index: 79476
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByKey_m8845F0D85AE0771B0D6FC36F4CDB52BE0F3D43AD_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (-1);
		RuntimeObject* L_0 = ___0_key;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF3719F0495F9D5A4339890BE2EB8999ACD068EFA(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_1 = L_1;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_2 = V_1;
		int32_t L_3 = L_2.____nodeID;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_4 = V_1;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNodePath_mA462180E40EFE84991C0B4E4CA85D960D8655784(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 55));
		V_0 = L_5;
	}

IL_001a:
	{
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 79477
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m579F0FCDCC9A79BC70EEE156F07CC896029A410B_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_node, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_node;
		int32_t L_2;
		L_2 = RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return L_2;
	}

IL_0010:
	{
		int32_t L_3 = ___0_node;
		int32_t L_4;
		L_4 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = ___0_node;
		int32_t L_6;
		L_6 = RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_6;
	}

IL_0021:
	{
		int32_t L_7 = ___0_node;
		RuntimeObject* L_8;
		L_8 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_9;
		L_9 = RBTree_1_SearchSubTree_m739962F4F45C09FA4CF594B0EBDBE94D778F7549(__this, 0, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 52));
		V_0 = L_9;
		int32_t L_10 = V_0;
		int32_t L_11 = ___0_node;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_12 = ___0_node;
		int32_t L_13;
		L_13 = RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_13;
	}

IL_003c:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		int32_t L_16 = ___0_node;
		int32_t L_17;
		L_17 = RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return ((int32_t)il2cpp_codegen_add(L_15, L_17));
	}
}
// Method Definition Index: 79478
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mA462180E40EFE84991C0B4E4CA85D960D8655784_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 ___0_path, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_1 = ___0_path;
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return L_3;
	}

IL_0015:
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_4 = ___0_path;
		int32_t L_5 = L_4.____mainTreeNodeID;
		if (L_5)
		{
			goto IL_002a;
		}
	}
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_6 = ___0_path;
		int32_t L_7 = L_6.____nodeID;
		int32_t L_8;
		L_8 = RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		return L_8;
	}

IL_002a:
	{
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_9 = ___0_path;
		int32_t L_10 = L_9.____mainTreeNodeID;
		int32_t L_11;
		L_11 = RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 57));
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_12 = ___0_path;
		int32_t L_13 = L_12.____nodeID;
		int32_t L_14;
		L_14 = RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		return ((int32_t)il2cpp_codegen_add(L_11, L_14));
	}
}
// Method Definition Index: 79479
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mBCE98E9CE148E35692561C8E3447BCD0DA72F2F3_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = L_2;
		goto IL_0037;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(L_11, 1))));
	}

IL_0034:
	{
		int32_t L_12 = V_1;
		___0_nodeId = L_12;
	}

IL_0037:
	{
		int32_t L_13 = ___0_nodeId;
		if (L_13)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 79480
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m1305DFA6E20E6D34D7496686C6CFFB676A0265F2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B4_1 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B5_1 = 0;
	int32_t G_B5_2 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_0 = L_2;
		goto IL_004f;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 23));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_12 = V_1;
		int32_t L_13;
		L_13 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_13)
		{
			G_B4_0 = L_11;
			G_B4_1 = L_8;
			goto IL_0048;
		}
		G_B3_0 = L_11;
		G_B3_1 = L_8;
	}
	{
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_16;
		L_16 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_15, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B5_0 = L_16;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0049;
	}

IL_0048:
	{
		G_B5_0 = 1;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0049:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B5_2, ((int32_t)il2cpp_codegen_add(G_B5_1, G_B5_0))));
	}

IL_004c:
	{
		int32_t L_17 = V_1;
		___0_nodeId = L_17;
	}

IL_004f:
	{
		int32_t L_18 = ___0_nodeId;
		if (L_18)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_19 = V_0;
		return L_19;
	}
}
// Method Definition Index: 79481
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 RBTree_1_GetNodeByIndex_m948B6DED575DEAF9BC7735B1CD602A208058485C_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_userIndex, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1 = __this->___root;
		int32_t L_2 = ___0_userIndex;
		int32_t L_3;
		L_3 = RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5(__this, L_1, ((int32_t)il2cpp_codegen_add(L_2, 1)), il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		V_0 = L_3;
		V_1 = 0;
		goto IL_0026;
	}

IL_001c:
	{
		int32_t L_4 = ___0_userIndex;
		int32_t L_5;
		L_5 = RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007(__this, L_4, (&V_1), il2cpp_rgctx_method(method->klass->rgctx_data, 59));
		V_0 = L_5;
	}

IL_0026:
	{
		int32_t L_6 = V_0;
		if (L_6)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_7 = __this->____accessMethod;
		if ((!(((uint32_t)2) == ((uint32_t)L_7))))
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_8 = ___0_userIndex;
		Exception_t* L_9;
		L_9 = ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054(L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0039:
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462((int32_t)((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0041:
	{
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		NodePath_tA355B40E34B64AADE90850F8BA7180852D3B1BD2 L_13;
		memset((&L_13), 0, sizeof(L_13));
		NodePath__ctor_m78E9206041A7104A8531998AA3DF9EC7DE5E4A45((&L_13), L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 53));
		return L_13;
	}
}
// Method Definition Index: 79482
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6A133AF17BE38F8B527CD83716760BF90D624007_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_index;
		___0_index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t* L_1 = ___1_satelliteRootId;
		*((int32_t*)L_1) = (int32_t)0;
		int32_t L_2 = __this->___root;
		V_0 = L_2;
		V_1 = (-1);
		goto IL_0088;
	}

IL_0013:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = V_1;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_6;
		goto IL_0088;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_8)
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_11 = ___0_index;
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		int32_t L_14;
		L_14 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_15;
		L_15 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		if ((((int32_t)L_11) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_12, L_15)), 1)))))
		{
			goto IL_005b;
		}
	}
	{
		int32_t* L_16 = ___1_satelliteRootId;
		int32_t L_17 = V_0;
		*((int32_t*)L_16) = (int32_t)L_17;
		int32_t L_18 = ___0_index;
		int32_t L_19 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_18, L_19)), 1));
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_20, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_22 = ___0_index;
		int32_t L_23;
		L_23 = RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5(__this, L_21, L_22, il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		return L_23;
	}

IL_005b:
	{
		int32_t L_24 = V_0;
		int32_t L_25;
		L_25 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_24, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (L_25)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_26 = ___0_index;
		int32_t L_27 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_26, L_27));
		goto IL_0080;
	}

IL_006b:
	{
		int32_t L_28 = ___0_index;
		int32_t L_29 = V_1;
		int32_t L_30 = V_0;
		int32_t L_31;
		L_31 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_30, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_32;
		L_32 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_31, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_28, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_29, L_32)), 1))));
	}

IL_0080:
	{
		int32_t L_33 = V_0;
		int32_t L_34;
		L_34 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_33, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		V_0 = L_34;
	}

IL_0088:
	{
		int32_t L_35 = V_0;
		if (!L_35)
		{
			goto IL_00ae;
		}
	}
	{
		int32_t L_36 = V_0;
		int32_t L_37;
		L_37 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_36, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_38;
		L_38 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_37, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_39 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		V_1 = L_39;
		int32_t L_40 = ___0_index;
		if ((!(((uint32_t)L_39) == ((uint32_t)L_40))))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_41 = V_0;
		int32_t L_42;
		L_42 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_41, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (L_42)
		{
			goto IL_0013;
		}
	}

IL_00ae:
	{
		int32_t L_43 = V_0;
		return L_43;
	}
}
// Method Definition Index: 79483
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1985EC887852D977760416BBE4644EB35499D6E5_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		goto IL_002f;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
		int32_t L_4 = ___1_index;
		int32_t L_5 = V_1;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_6 = V_0;
		___0_x_id = L_6;
		goto IL_002f;
	}

IL_001d:
	{
		int32_t L_7 = V_1;
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_9 = ___0_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		___0_x_id = L_10;
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_1;
		___1_index = ((int32_t)il2cpp_codegen_subtract(L_11, L_12));
	}

IL_002f:
	{
		int32_t L_13 = ___0_x_id;
		if (L_13)
		{
			goto IL_0002;
		}
	}

IL_0032:
	{
		int32_t L_14 = ___0_x_id;
		return L_14;
	}
}
// Method Definition Index: 79484
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m35626D9659BB9AE29166EC4E41AB61BD5CD68FBA_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 79485
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Add_mECEC8AF0BF9CCB06504739491EA4AAAAF8C88ADE_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 79486
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_GetEnumerator_m2F0E5ABAED8811AF73BCA874B56A03F87908F951_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) 
{
	{
		RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A L_0;
		memset((&L_0), 0, sizeof(L_0));
		RBTreeEnumerator__ctor_m328625AEF6FC9DE908D967C4537628D1B2B61700((&L_0), __this, il2cpp_rgctx_method(method->klass->rgctx_data, 61));
		RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 60), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 79487
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		int32_t L_0 = ___0_nodeId;
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_1 = ___0_nodeId;
		RuntimeObject* L_2;
		L_2 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		RuntimeObject* L_3 = ___1_item;
		if ((!(((RuntimeObject*)(RuntimeObject*)L_2) == ((RuntimeObject*)(RuntimeObject*)L_3))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_4 = ___0_nodeId;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNode_m579F0FCDCC9A79BC70EEE156F07CC896029A410B(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 62));
		return L_5;
	}

IL_0021:
	{
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		RuntimeObject* L_8 = ___1_item;
		int32_t L_9;
		L_9 = RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E(__this, L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
		int32_t L_10 = L_9;
		V_0 = L_10;
		if ((((int32_t)L_10) == ((int32_t)(-1))))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_11 = V_0;
		return L_11;
	}

IL_0036:
	{
		int32_t L_12 = ___0_nodeId;
		int32_t L_13;
		L_13 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		RuntimeObject* L_14 = ___1_item;
		int32_t L_15;
		L_15 = RBTree_1_IndexOf_mC4650C040FAD95BD3F81362BCD765C733564B53E(__this, L_13, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
		int32_t L_16 = L_15;
		V_0 = L_16;
		int32_t L_17 = V_0;
		return L_17;
	}

IL_004b:
	{
		int32_t L_18 = V_0;
		return L_18;
	}
}
// Method Definition Index: 79488
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m2503BCE57A1429AEEEB22C7475C07346E71D6618_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_position, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_position;
		RuntimeObject* L_1 = ___1_item;
		int32_t L_2;
		L_2 = RBTree_1_InsertAt_m55077BF0B4CAA5C5ABD5911CCB68C789D7652B4D(__this, L_0, L_1, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 64));
		return L_2;
	}
}
// Method Definition Index: 79489
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_m55077BF0B4CAA5C5ABD5911CCB68C789D7652B4D_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_position, RuntimeObject* ___1_item, bool ___2_append, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___1_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mCD240B40D292EF9307F03939556ACA325503DA73(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = ___0_position;
		bool L_4 = ___2_append;
		int32_t L_5;
		L_5 = RBTree_1_RBInsert_m25C1F9B8FA733750F51C334ED01E4EF680C3EBBC(__this, 0, L_2, 0, L_3, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 38));
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 79490
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RemoveAt_mCD1E524DC3AC069433DE12C7B452DB237E208D21_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_position, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_position;
		RuntimeObject* L_1;
		L_1 = RBTree_1_DeleteByIndex_m77EB3F96268C89DEA1218BA5DB3CB1A8EEC073F6(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 65));
		return;
	}
}
// Method Definition Index: 79491
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Clear_m151E8E1EDCEC1E206685E669A25AB2E7CA40293A_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, const RuntimeMethod* method) 
{
	{
		RBTree_1_InitTree_mF38DBB7EC2C944A42C6E22B0EE84ABAC77882781(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 1));
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		return;
	}
}
// Method Definition Index: 79492
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m121CD9E5230E60651FEDA1684A99BBE78BAB5781_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		V_0 = L_4;
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_5, NULL);
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_003a;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003a:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1(__this, L_10, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		V_1 = L_11;
		V_2 = 0;
		goto IL_006c;
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		int32_t L_13 = V_1;
		RuntimeObject* L_14;
		L_14 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_13, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		int32_t L_15 = ___1_index;
		int32_t L_16 = V_2;
		NullCheck(L_12);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_12, L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), NULL);
		int32_t L_17 = V_1;
		int32_t L_18;
		L_18 = RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0(__this, L_17, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_18;
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006c:
	{
		int32_t L_20 = V_2;
		int32_t L_21 = V_0;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_004b;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 79493
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m6B9054A8EA421231E2399E1217118F8B5E503A57_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		V_0 = L_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = RBTree_1_get_Count_m1F1E9F00D8DEEB51D299E897DDAD8F4903E2FA9B(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 66));
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_5)->max_length)), L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0037;
		}
	}
	{
		Exception_t* L_8;
		L_8 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, method);
	}

IL_0037:
	{
		int32_t L_9 = __this->___root;
		int32_t L_10;
		L_10 = RBTree_1_Minimum_m04A2B22ED80334294DFDB982AF71368FF96175C1(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		V_1 = L_10;
		V_2 = 0;
		goto IL_0064;
	}

IL_0048:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = ___0_array;
		int32_t L_12 = ___1_index;
		int32_t L_13 = V_2;
		int32_t L_14 = V_1;
		RuntimeObject* L_15;
		L_15 = RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE(__this, L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 30));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_12, L_13))), (RuntimeObject*)L_15);
		int32_t L_16 = V_1;
		int32_t L_17;
		L_17 = RBTree_1_Successor_mBC120AD827A51511A7C816DDE34B411DCB52E9B0(__this, L_16, il2cpp_rgctx_method(method->klass->rgctx_data, 24));
		V_1 = L_17;
		int32_t L_18 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}

IL_0064:
	{
		int32_t L_19 = V_2;
		int32_t L_20 = V_0;
		if ((((int32_t)L_19) < ((int32_t)L_20)))
		{
			goto IL_0048;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 79494
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_m120F92D6A66DAEE6286EC44B7815455485D312E4_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_rightNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId = L_6;
		return;
	}
}
// Method Definition Index: 79495
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mAE236B89D5ECB3912FB6B88C73A7FF8186FFA052_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_leftNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId = L_6;
		return;
	}
}
// Method Definition Index: 79496
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_mF5DDAE78F573B9633DA88D22C5B3E0BB67411493_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_parentNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId = L_6;
		return;
	}
}
// Method Definition Index: 79497
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m782DB769F0783E833F7C8327C79E48B53EB74FA2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_color;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor = L_6;
		return;
	}
}
// Method Definition Index: 79498
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_mBBCC4BFD81ED932DEF3BAACA07389DAF7017AFF9_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, RuntimeObject* ___1_key, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		RuntimeObject* L_6 = ___1_key;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode), (void*)L_6);
		return;
	}
}
// Method Definition Index: 79499
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mADA41B6665596F49964D1AC259BC1CAEDEB86AC8_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_nextNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId = L_6;
		return;
	}
}
// Method Definition Index: 79500
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_m0EBB22E8908E7A97007F5BA1CB2F7BE4ED2AB1FD_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_size;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize = L_6;
		return;
	}
}
// Method Definition Index: 79501
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_mC7A31D096BC854B6993FED4FE86BE2B2AB33281E_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *((int32_t*)L_7);
		*((int32_t*)L_7) = (int32_t)((int32_t)il2cpp_codegen_add(L_8, 1));
		return;
	}
}
// Method Definition Index: 79502
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_m5B049EA2694E6343E2D30EDCDB34CC4C44A0FD08_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1(__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 26));
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2(__this, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 21));
		int32_t L_5;
		L_5 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_6, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		if (!L_7)
		{
			G_B2_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
			goto IL_0033;
		}
		G_B1_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05(__this, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 25));
		int32_t L_10;
		L_10 = RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 33));
		G_B3_0 = L_10;
		G_B3_1 = G_B1_0;
		goto IL_0034;
	}

IL_0033:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0034:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B3_1, G_B3_0));
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_11 = __this->____pageTable;
		int32_t L_12 = ___0_nodeId;
		NullCheck(L_11);
		int32_t L_13 = ((int32_t)(L_12>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_15 = L_14->____slots;
		int32_t L_16 = ___0_nodeId;
		NullCheck(L_15);
		int32_t L_17 = V_0;
		((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_16&((int32_t)65535))))))->____subTreeSize = L_17;
		return;
	}
}
// Method Definition Index: 79503
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m63463D3F02F9E581B66DAC4F5311669F2284C603_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *((int32_t*)L_7);
		*((int32_t*)L_7) = (int32_t)((int32_t)il2cpp_codegen_subtract(L_8, 1));
		return;
	}
}
// Method Definition Index: 79504
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_mC2B707153B503CB816DDE1CED80604D16F4680F2_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId;
		return L_6;
	}
}
// Method Definition Index: 79505
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_mFDB3C5ADD048B375B7649866196AA662B34FE7E1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId;
		return L_6;
	}
}
// Method Definition Index: 79506
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mF131D5025BC9BFB6F24F78B608B5B85A7C2B4E25_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId;
		return L_6;
	}
}
// Method Definition Index: 79507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_mE7FE03FE3DA1675B1AB2EA861D8CE9C0F90506E1_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor;
		return L_6;
	}
}
// Method Definition Index: 79508
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m283CA7267B0E07C0F7C86E1A0B9106398E64BE05_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId;
		return L_6;
	}
}
// Method Definition Index: 79509
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m7B3B4EC61186E6264F1C32FCE0C28CF982C97A7D_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize;
		return L_6;
	}
}
// Method Definition Index: 79510
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_Key_m44FD36D6E9B9BBF993102D058D5FA268861802CE_gshared (RBTree_1_tAC9E374B8EB24E3B4F23E6597A887D825D581669* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	{
		TreePageU5BU5D_t83E46A69994CD4F1584A98171754D3F2728C8EDB* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t0F850FD85FF7F257D5AE177EE5D0F953B15E505D* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		RuntimeObject* L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* Array_Empty_TisRotationBySpeedModule_tBCB7E7C1B402D1492310016D5F8FBBA4C15C26A6_mA0D9CFABD04BEF3BFE482AE641DCD6F0C1597FA9_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		RotationBySpeedModuleU5BU5D_tFC82BD47383BAC5155E20F4CACA0B1D3377CA989* L_0 = ((EmptyArray_1_tDA1E10579FDDCE25837B4F203EABDCA5251082FB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* Array_Empty_TisRotationOverLifetimeModule_tEE08858451167B6DDE6DD36FDCF11E74C77D79E6_m3E7ABA71381D6C3DA7508146A094FE8C9C5C7436_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		RotationOverLifetimeModuleU5BU5D_t50CBEBBC6B542E064BD30EB9EB49BCD9B5F419C8* L_0 = ((EmptyArray_1_tFF1C726B7AD2D4CB615066440DB2BD360077F74E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* Array_Empty_TisShapeModule_tAA38A0C5305DF2F9D96F89D4B8F762E2D034D8B2_m23574AE640623A2874871290CD7F26FE026C60FE_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		ShapeModuleU5BU5D_t8997568E698C9B1509FCDFE401084FF80AB60243* L_0 = ((EmptyArray_1_t151CEED89EBC00271F4BF4ACC9D4E781D780866E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* Array_Empty_TisSizeBySpeedModule_t73995CB54A0D1B06BA100EA77972D37CDF7B4DC4_m9AA9EFC539DB7558A084DA01995E1416885100E0_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		SizeBySpeedModuleU5BU5D_tEF4645160713AF1309F815C4B95C79975BA2D221* L_0 = ((EmptyArray_1_tBA9A911B01CFC769E520FBF101B83CC77C18ECCF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* Array_Empty_TisSizeOverLifetimeModule_t6711CE9659123CAA5BFBFDFA9F53174CD979AC0C_m3A84DF47DB367D4CDF792D5F7DF11100A974F13D_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		SizeOverLifetimeModuleU5BU5D_t31052F8FFC4F64017ABA0B123070F572D37A29A3* L_0 = ((EmptyArray_1_tDEA777902FAFA73B2D66B35576B82407F616798F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* Array_Empty_TisSubEmittersModule_t94F5AD231EAFB50A16E697186A630B07BF8B949B_m68BA68C658B6882B6E960B75E942EA462D773B90_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		SubEmittersModuleU5BU5D_t0F0D2688875FC82644111B1ECCC27FA6B775A483* L_0 = ((EmptyArray_1_t45ACA127E94E3425602D4677D3A2A8DF9A62AC4C_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* Array_Empty_TisTextureSheetAnimationModule_tB53F451F252E24ACC3EF80D770DB4FBE1A13D1F6_m862A5BA24E230AB8040592E40E0BB35D2F9E4C1B_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		TextureSheetAnimationModuleU5BU5D_t294B4FDB3F59114F90368A7AA313353265166E7F* L_0 = ((EmptyArray_1_t2AEFF5629DF828443FB4E93984DDA89352CA99D9_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* Array_Empty_TisTrailModule_tC466413E68A674741F1CEAE0CFD7317631E8040D_m5E837DC356E7055EC66201B81D083D2B10C46847_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		TrailModuleU5BU5D_tF0631E2EE51F8E6C61A6A671BC9CE331ABE752DC* L_0 = ((EmptyArray_1_t2B80EF52C4FCF840DBDC03E7CBF5D78B21674522_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* Array_Empty_TisTriggerModule_tDEE844919206259DA831ADCA3B1B2D915CB767B1_m59FF55B8FFA23A27220CDE44EA6FCDECBEB4AE06_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		TriggerModuleU5BU5D_tFB580E18A1B1335583C5C10E80CE741283796D80* L_0 = ((EmptyArray_1_t3014CE3C51BB8D288EE928901E5BE2DE487639F7_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 3326
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* Array_Empty_TisVelocityOverLifetimeModule_tB4A3291E3D2E850257EE3F8344AAEDA06D7FCE56_m080870BF6555D8A370950DBC1D2C718B0D09F5BE_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		VelocityOverLifetimeModuleU5BU5D_t2C8DE36F44CEA615D11840EF8918490A715D5734* L_0 = ((EmptyArray_1_tB72192C297310B25DA15BD93F344C7BD7F1E0DBC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 79522
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_gshared_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 79522
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_get_Current_m948775C3F9A3EB7A07354D1870165849B3CBD1CD_gshared_inline (RBTreeEnumerator_t3C01D9560885FADFFCE590C8A9CE34A3BEA77A9A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 79522
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_gshared_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),4)), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
// Method Definition Index: 79515
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->____inUseCount = L_0;
		return;
	}
}
// Method Definition Index: 79516
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____pageId;
		return L_0;
	}
}
// Method Definition Index: 79517
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->____pageId = L_0;
		return;
	}
}
// Method Definition Index: 79514
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_gshared_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseCount;
		return L_0;
	}
}
// Method Definition Index: 79515
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_m8E1B3603F6197A4CC81CE5F9FEC441342EA079DD_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->____inUseCount = L_0;
		return;
	}
}
// Method Definition Index: 79516
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_mAB3203DD4C550C1E6CDC4DF4367B61A00DC0A367_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____pageId;
		return L_0;
	}
}
// Method Definition Index: 79517
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m4637CDAE893DECB44B1201D9DFEF3C18C0DB5257_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->____pageId = L_0;
		return;
	}
}
// Method Definition Index: 79514
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_m51D4FB92286C827692E858691E4E1F47FCBCD2B1_gshared_inline (TreePage_tE13370C06FAC7132F4E8B67FB0B341D5A42CEE08* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____inUseCount;
		return L_0;
	}
}
