
void FUN_007f51a0(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int local_224;
  undefined4 *local_220;
  char local_21c [264];
  char local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937596;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*(int *)(in_ECX + 0x330) != 0) {
    local_220 = (undefined4 *)(in_ECX + 0x308);
    local_224 = 0;
    do {
      local_114 = '\0';
      _memset(local_113,0,0xff);
      if (*(int *)(in_ECX + 0x33c) == 1) {
        piVar3 = (int *)(in_ECX + 800);
        if (0xf < *(uint *)(in_ECX + 0x334)) {
          piVar3 = (int *)*piVar3;
        }
        _sprintf(&local_114,"Map/Skybox/%s%s.dds",piVar3,(&PTR_DAT_00d63a48)[local_224]);
      }
      else {
        piVar3 = (int *)(in_ECX + 800);
        if (*(int *)(in_ECX + 0x33c) == 2) {
          if (0xf < *(uint *)(in_ECX + 0x334)) {
            piVar3 = (int *)*piVar3;
          }
          _sprintf(&local_114,"Map/Skybox/%s%d.dds",piVar3,local_224);
        }
        else {
          if (0xf < *(uint *)(in_ECX + 0x334)) {
            piVar3 = (int *)*piVar3;
          }
          _sprintf(&local_114,"Map/Skybox/%s.dds",piVar3,uVar2);
        }
      }
      __splitpath(&local_114,(char *)0x0,(char *)0x0,local_21c,(char *)0x0);
      if ((DAT_00fe1ac0 & 1) == 0) {
        DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
        local_8 = 0;
        FUN_007bb970();
        _atexit((_func_4879 *)&LAB_00bceac0);
        local_8 = 0xffffffff;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
      iVar4 = (*DAT_00fe1ae8)(local_21c,&local_114);
      SetEvent(DAT_00fe1b2c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
      if (iVar4 == 0) {
        *local_220 = 0;
      }
      else {
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 1;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
          if ((DAT_00fb79e8 & 1) == 0) {
            DAT_00fb79e8 = DAT_00fb79e8 | 1;
            local_8 = 2;
            FUN_00798de0();
            _atexit((_func_4879 *)&LAB_00bcd2e0);
            local_8 = 0xffffffff;
          }
        }
        iVar4 = DAT_00fb76a8;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 3;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        puVar5 = (uint *)FUN_0079be00(local_21c);
        uVar1 = *puVar5;
        if (uVar1 == 0) {
LAB_007f541d:
          puVar7 = (undefined4 *)0x0;
        }
        else {
          uVar6 = uVar1 & 0xffff;
          if (((uint)((*(int *)(iVar4 + 0x104) - *(int *)(iVar4 + 0x100)) / 0x34) <= uVar6) ||
             (*(uint *)(*(int *)(iVar4 + 0x110) + uVar6 * 4) != uVar1 >> 0x10)) goto LAB_007f541d;
          puVar7 = (undefined4 *)(uVar6 * 0x34 + *(int *)(iVar4 + 0x100));
        }
        uVar1 = DAT_00fe3314 & 1;
        *local_220 = *puVar7;
        if (uVar1 == 0) {
          DAT_00fe3314 = DAT_00fe3314 | 1;
          local_8 = 4;
          FUN_007ed9f0();
          _atexit((_func_4879 *)&LAB_00bd0ae0);
          local_8 = 0xffffffff;
        }
        FUN_007edbf0(&DAT_00fe3318,&local_114);
      }
      local_220 = local_220 + 1;
      local_224 = local_224 + 1;
    } while (local_224 < 6);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

