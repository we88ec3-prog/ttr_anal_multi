
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Fput(class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >,class std::ios_base &,unsigned short,char const *,unsigned
   int,unsigned int,unsigned int,unsigned int)const 
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __cdecl
   std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Fput(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,class
   std::ios_base &,wchar_t,char const *,unsigned int,unsigned int,unsigned int,unsigned int)const 
   
   Library: Visual Studio 2010 Release */

void Fput(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
         ushort param_6,char ****param_7,int param_8,int param_9,int param_10,size_t param_11)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  lconv *plVar6;
  char ****ppppcVar7;
  char ****_Str;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  undefined *puVar12;
  undefined1 local_8c [4];
  int local_88;
  uint local_84;
  uint local_80;
  int *local_7c;
  int local_78;
  uint local_74;
  undefined4 local_70;
  int local_6c;
  undefined1 local_68 [4];
  void *local_64;
  int local_60;
  char local_5c [4];
  int local_58;
  size_t local_54;
  void *local_50;
  char ***local_4c [5];
  uint local_38;
  char ***local_30 [4];
  size_t local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x8885cc;
  local_80 = (uint)param_6;
  local_60 = param_8;
  local_78 = param_9;
  local_58 = param_10;
  local_54 = param_11;
  uVar5 = FUN_004318d0(&local_6c);
  local_8 = 0;
  local_7c = (int *)use_facet<>(uVar5);
  local_8 = 0xffffffff;
  FUN_004327c0();
  grouping(local_4c);
  local_8 = 1;
  local_84 = (**(code **)(*local_7c + 8))();
  local_20 = 0;
  local_84 = local_84 & 0xffff;
  local_1c = 0xf;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_74 = _Maklocchr<>(0x30,0,param_1 + 8);
  local_74 = local_74 & 0xffff;
  if ((*(char *)param_7 == '+') || (*(char *)param_7 == '-')) {
    local_88 = 1;
  }
  else {
    local_88 = 0;
  }
  plVar6 = _localeconv();
  local_5c[0] = *plVar6->decimal_point;
  local_5c[1] = 'e';
  local_5c[2] = '\0';
  local_50 = _memchr(param_7,0x65,local_54);
  local_64 = _memchr(param_7,(int)local_5c[0],local_54);
  if (local_64 == (void *)0x0) {
    local_58 = 0;
  }
  ppppcVar7 = (char ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppcVar7 = local_4c;
  }
  if (*(char *)ppppcVar7 != '\x7f') {
    ppppcVar7 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar7 = local_4c;
    }
    if ('\0' < *(char *)ppppcVar7) {
      FUN_00401fc0(param_7,local_54);
      if (local_50 == (void *)0x0) {
        FUN_00429630(local_58,0x30);
      }
      else {
        if (local_64 == (void *)0x0) {
          FUN_00429630(local_60,0x30);
          local_60 = 0;
        }
        FUN_004329c0((int)local_50 - (int)param_7,local_58,0x30);
      }
      if (local_64 == (void *)0x0) {
        FUN_00429630(local_60,0x30);
      }
      else {
        local_64 = (void *)((int)local_64 - (int)param_7);
        FUN_004329c0((int)local_64 + 1,local_78,0x30);
        FUN_004329c0(local_64,local_60,0x30);
        local_78 = 0;
      }
      local_60 = 0;
      ppppcVar7 = (char ****)local_4c[0];
      if (local_38 < 0x10) {
        ppppcVar7 = local_4c;
      }
      _Str = (char ****)local_30[0];
      if (local_1c < 0x10) {
        _Str = local_30;
      }
      local_50 = (void *)_strcspn((char *)_Str,local_5c);
      while (((cVar1 = *(char *)ppppcVar7, cVar1 != '\x7f' && ('\0' < cVar1)) &&
             ((uint)(int)cVar1 < (uint)((int)local_50 - local_88)))) {
        local_50 = (void *)((int)local_50 - (int)cVar1);
        FUN_004329c0(local_50,1,0);
        if ('\0' < *(char *)((int)ppppcVar7 + 1)) {
          ppppcVar7 = (char ****)((int)ppppcVar7 + 1);
        }
      }
      param_7 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        param_7 = local_30;
      }
      local_58 = 0;
      local_54 = local_20;
    }
  }
  uVar9 = *(uint *)(param_5 + 0x20);
  uVar8 = local_54 + local_58 + local_78 + local_60;
  if (((*(int *)(param_5 + 0x24) < 0) || ((*(int *)(param_5 + 0x24) < 1 && (uVar9 == 0)))) ||
     (uVar9 <= uVar8)) {
    local_50 = (void *)0x0;
  }
  else {
    local_50 = (void *)(uVar9 - uVar8);
  }
  uVar9 = *(uint *)(param_5 + 0x14) & 0x1c0;
  if (uVar9 != 0x40) {
    if ((uVar9 == 0x100) && (local_88 != 0)) {
      puVar10 = (undefined4 *)Putc(param_1,local_68,param_3,param_4,param_7,1);
      param_3 = *puVar10;
      param_4 = puVar10[1];
      param_7 = (char ****)((int)param_7 + 1);
      local_54 = local_54 - 1;
    }
    puVar10 = (undefined4 *)Rep(param_1,local_68,param_3,param_4,local_80,local_50);
    param_3 = *puVar10;
    param_4 = puVar10[1];
    local_50 = (void *)0x0;
  }
  pvVar11 = _memchr(param_7,(int)local_5c[0],local_54);
  if (pvVar11 != (void *)0x0) {
    local_64 = (void *)(((int)pvVar11 - (int)param_7) + 1);
    puVar10 = (undefined4 *)
              Putgrouped(param_1,local_8c,param_3,param_4,param_7,(int)pvVar11 - (int)param_7,
                         local_84);
    puVar10 = (undefined4 *)Rep(param_1,local_8c,*puVar10,puVar10[1],local_74,local_60);
    uVar5 = *puVar10;
    iVar2 = puVar10[1];
    uVar4 = (**(code **)(*local_7c + 4))();
    local_70 = uVar5;
    local_6c = iVar2;
    FID_conflict_operator_(uVar4);
    puVar10 = (undefined4 *)Rep(param_1,&local_70,local_70,local_6c,local_74,local_78);
    param_3 = *puVar10;
    param_4 = puVar10[1];
    param_7 = (char ****)((int)param_7 + (int)local_64);
    local_54 = local_54 - (int)local_64;
  }
  pvVar11 = _memchr(param_7,0x65,local_54);
  if (pvVar11 != (void *)0x0) {
    local_6c = ((int)pvVar11 - (int)param_7) + 1;
    puVar10 = (undefined4 *)
              Putgrouped(param_1,local_68,param_3,param_4,param_7,(int)pvVar11 - (int)param_7,
                         local_84);
    puVar10 = (undefined4 *)Rep(param_1,local_68,*puVar10,puVar10[1],local_74,local_58);
    local_58 = 0;
    puVar12 = &DAT_00bf94d4;
    if ((*(byte *)(param_5 + 0x14) & 4) == 0) {
      puVar12 = &DAT_00bf94d8;
    }
    puVar10 = (undefined4 *)Putc(param_1,local_68,*puVar10,puVar10[1],puVar12,1);
    param_3 = *puVar10;
    param_4 = puVar10[1];
    param_7 = (char ****)((int)param_7 + local_6c);
    local_54 = local_54 - local_6c;
  }
  puVar10 = (undefined4 *)Putgrouped(param_1,&local_70,param_3,param_4,param_7,local_54,local_84);
  puVar10 = (undefined4 *)Rep(param_1,local_68,*puVar10,puVar10[1],local_74,local_58);
  uVar5 = *puVar10;
  uVar3 = puVar10[1];
  *(undefined4 *)(param_5 + 0x20) = 0;
  *(undefined4 *)(param_5 + 0x24) = 0;
  Rep(param_1,param_2,uVar5,uVar3,local_80,local_50);
  FUN_00402f30(1,0);
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

