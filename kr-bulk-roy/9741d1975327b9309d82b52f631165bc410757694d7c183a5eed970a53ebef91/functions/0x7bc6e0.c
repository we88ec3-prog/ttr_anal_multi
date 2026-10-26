
void FUN_007bc6e0(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int *unaff_ESI;
  undefined1 auStack_5c [4];
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined **local_48;
  undefined4 local_44;
  int *local_40;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  int local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00934fe1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  local_4c = param_2;
  local_50 = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffffff00;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar2 - (int)(param_1 + 1));
  local_c = 1;
  local_58 = FUN_007b6f30(local_3c);
  if (local_58 != *(int *)(in_ECX + 0x28)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 == '\0') {
      piVar3 = &local_58;
      goto LAB_007bc7d5;
    }
  }
  local_54 = *(int *)(in_ECX + 0x28);
  piVar3 = &local_54;
LAB_007bc7d5:
  iVar4 = *piVar3;
  local_c = 0xffffffff;
  if (0xf < local_28) {
    FUN_0089120c(local_3c[0]);
  }
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffffff00;
  if (iVar4 == *(int *)(local_50 + 0x28)) {
    local_54 = FUN_00891268(0x28);
    local_c = 2;
    if (local_54 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_007bb920(3);
    }
    local_c = 0xffffffff;
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffffff00;
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_54 = iVar4;
    FUN_00402a70(param_1,(int)pcVar2 - (int)(param_1 + 1));
    local_c = 3;
    local_20 = iVar4;
    uVar5 = FUN_00552de0(local_3c);
    FUN_007e2910(in_ECX + 0x24,&local_48,uVar5);
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c[0]);
    }
    local_50 = 0;
    local_58 = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    local_44 = FUN_0079a5f0(&DAT_00fb76a8);
    local_40 = &local_58;
    local_48 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
               ::__l2::CreateTextureFromFileBox::vftable;
    iVar6 = FUN_00737d40();
    if (iVar6 == 0) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 5;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_c = 6;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_c = 0xffffffff;
        }
      }
      (**(code **)(*DAT_00fb76a8 + 0x50))(param_1,local_58,&local_50);
      (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    }
    *(undefined4 *)(iVar4 + 0x1c) = 1;
    iVar4 = local_54;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x28);
  }
  *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 7;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

