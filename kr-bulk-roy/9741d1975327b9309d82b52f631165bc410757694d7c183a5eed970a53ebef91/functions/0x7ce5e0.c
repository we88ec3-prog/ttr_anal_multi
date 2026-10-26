
void FUN_007ce5e0(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined ***pppuVar4;
  undefined4 uVar5;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 auStack_74 [4];
  undefined **local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_64;
  undefined **local_60;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  uint local_40 [4];
  undefined4 local_30;
  uint local_2c;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00934e3c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffffff00;
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  local_c = 0;
  local_60 = (undefined **)FUN_007d0110(local_5c);
  if ((local_60 == *(undefined ***)(unaff_EDI + 4)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0'))
  {
    local_70 = *(undefined ***)(unaff_EDI + 4);
    pppuVar4 = &local_70;
  }
  else {
    pppuVar4 = &local_60;
  }
  local_70 = *pppuVar4;
  local_c = 0xffffffff;
  if (0xf < local_48) {
    FUN_0089120c(local_5c[0]);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffffff00;
  if (local_70 == *(undefined ***)(unaff_EDI + 4)) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    local_6c = FUN_0079a5f0(&DAT_00fb76a8);
    local_68 = &local_64;
    local_64 = 0;
    local_70 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
               ::__l2::CreateTextureFromFileBox::vftable;
    local_70 = (undefined **)FUN_00737d40();
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_c = 2;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_c = 0xffffffff;
    }
    FUN_007edbf0(&DAT_00fe3318,unaff_ESI);
    if (local_70 == (undefined **)0x0) {
      local_6c = local_64;
      local_2c = 0xf;
      local_30 = 0;
      local_40[0] = local_40[0] & 0xffffff00;
      pcVar3 = unaff_ESI;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
      local_24 = 1;
      local_20 = local_6c;
      local_c = 3;
      uVar5 = FUN_007d0570(local_40);
      FUN_007d02a0(unaff_EDI,&local_70,uVar5);
      if (0xf < local_2c) {
        FUN_0089120c(local_40[0]);
      }
    }
  }
  else {
    local_70[10] = local_70[10] + 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

