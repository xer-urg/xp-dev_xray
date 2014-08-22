////////////////////////////////////////////////////////////////////////////
//	Module 		: script_binder_object_wrapper.cpp
//	Created 	: 29.03.2004
//  Modified 	: 29.03.2004
//	Author		: Dmitriy Iassenev
//	Description : Script object binder wrapper
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "script_binder_object_wrapper.h"
#include "script_game_object.h"
#include "xrServer_Objects_ALife.h"
#include "../../xrNetServer/net_utils.h"
#include "../../build_config_defines.h"
#include "GameObject.h"

#ifdef PERF_CHECK
#pragma message("alpet: ������ PERF_CHECK �� ������������� ��� trunk/release")
#pragma optimize("t", on)
#endif 

CScriptBinderObjectWrapper::CScriptBinderObjectWrapper	(CScriptGameObject *object) :
	CScriptBinderObject	(object)
{
}

CScriptBinderObjectWrapper::~CScriptBinderObjectWrapper ()
{
}

void CScriptBinderObjectWrapper::reinit					()
{
	luabind::call_member<void>		(this,"reinit");
}

void CScriptBinderObjectWrapper::reinit_static			(CScriptBinderObject *script_binder_object)
{
	script_binder_object->CScriptBinderObject::reinit	();
}

void CScriptBinderObjectWrapper::reload					(LPCSTR section)
{
	luabind::call_member<void>		(this,"reload",section);
}

void CScriptBinderObjectWrapper::reload_static			(CScriptBinderObject *script_binder_object, LPCSTR section)
{
	script_binder_object->CScriptBinderObject::reload	(section);
}

bool CScriptBinderObjectWrapper::net_Spawn				(SpawnType DC)
{
	bool result;
	__try
	{
#ifdef PERF_CHECK
		SetThreadAffinityMask(GetCurrentThread(), 0x0002);
#endif
		result = (luabind::call_member<bool>(this, "net_spawn", DC));
	}
	__finally
	{
#ifdef PERF_CHECK
		SetThreadAffinityMask(GetCurrentThread(), 0xFFFF);
#endif
	}
	
	return result;
}

bool CScriptBinderObjectWrapper::net_Spawn_static		(CScriptBinderObject *script_binder_object, SpawnType DC)
{
	return							(script_binder_object->CScriptBinderObject::net_Spawn(DC));
}

void CScriptBinderObjectWrapper::net_Destroy			()
{
	luabind::call_member<void>		(this,"net_destroy");
}

void CScriptBinderObjectWrapper::net_Destroy_static		(CScriptBinderObject *script_binder_object)
{
	script_binder_object->CScriptBinderObject::net_Destroy();
}

void CScriptBinderObjectWrapper::net_Import				(NET_Packet *net_packet)
{
	luabind::call_member<void>		(this,"net_import",net_packet);
}

void CScriptBinderObjectWrapper::net_Import_static		(CScriptBinderObject *script_binder_object, NET_Packet *net_packet)
{
	script_binder_object->CScriptBinderObject::net_Import	(net_packet);
}

void CScriptBinderObjectWrapper::net_Export				(NET_Packet *net_packet)
{
	luabind::call_member<void>		(this,"net_export",net_packet);
}

void CScriptBinderObjectWrapper::net_Export_static		(CScriptBinderObject *script_binder_object, NET_Packet *net_packet)
{
	script_binder_object->CScriptBinderObject::net_Export	(net_packet);
}

void CScriptBinderObjectWrapper::shedule_Update			(u32 time_delta)
{	
	__try
	{
#ifdef PERF_CHECK
		CGameObject *obj = &this->m_object->object();
		if (obj && obj->cast_actor())
			SetThreadAffinityMask(GetCurrentThread(), 0x0008);
		else
			SetThreadAffinityMask(GetCurrentThread(), 0x0004);
#endif		
		luabind::call_member<void>(this, "update", time_delta);
	}
	__finally
	{
#ifdef PERF_CHECK
		SetThreadAffinityMask(GetCurrentThread(), 0x0001);
#endif
	}
}

void CScriptBinderObjectWrapper::shedule_Update_static	(CScriptBinderObject *script_binder_object, u32 time_delta)
{
	script_binder_object->CScriptBinderObject::shedule_Update	(time_delta);
}

void CScriptBinderObjectWrapper::save					(NET_Packet *output_packet)
{
	luabind::call_member<void>		(this,"save",output_packet);
}

void CScriptBinderObjectWrapper::save_static			(CScriptBinderObject *script_binder_object, NET_Packet *output_packet)
{
	script_binder_object->CScriptBinderObject::save		(output_packet);
}

void CScriptBinderObjectWrapper::load					(IReader *input_packet)
{
	luabind::call_member<void>		(this,"load",input_packet);
}

void CScriptBinderObjectWrapper::load_static			(CScriptBinderObject *script_binder_object, IReader *input_packet)
{
	script_binder_object->CScriptBinderObject::load		(input_packet);
}

bool CScriptBinderObjectWrapper::net_SaveRelevant		()
{
	return							(luabind::call_member<bool>(this,"net_save_relevant"));
}

bool CScriptBinderObjectWrapper::net_SaveRelevant_static(CScriptBinderObject *script_binder_object)
{
	return							(script_binder_object->CScriptBinderObject::net_SaveRelevant());
}

void CScriptBinderObjectWrapper::net_Relcase			(CScriptGameObject *object)
{
	luabind::call_member<void>		(this,"net_Relcase",object);
}

void CScriptBinderObjectWrapper::net_Relcase_static		(CScriptBinderObject *script_binder_object, CScriptGameObject *object)
{
	script_binder_object->CScriptBinderObject::net_Relcase	(object);
}