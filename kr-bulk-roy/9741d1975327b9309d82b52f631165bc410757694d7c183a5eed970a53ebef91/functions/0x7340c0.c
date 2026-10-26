
void FUN_007340c0(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *in_ECX;
  int iVar6;
  char *in_EDX;
  undefined4 *puVar7;
  undefined4 ****ppppuVar8;
  undefined4 *puVar9;
  undefined1 auStack_64 [4];
  int local_60;
  undefined **local_5c;
  undefined4 *local_58;
  undefined4 ***local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 local_38 [4];
  int local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_00926756;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_60 = param_1;
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (undefined4 ***)((uint)local_54[0] & 0xffffff00);
  local_c = 0;
  if (in_ECX == (char *)0x0) {
    pcVar3 = in_EDX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
    goto LAB_00734204;
  }
  pcVar3 = in_ECX;
  if (*in_ECX == '\0') {
    pcVar3 = in_EDX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
    goto LAB_00734204;
  }
  do {
    pcVar4 = pcVar3;
    pcVar3 = pcVar4 + 1;
  } while (*pcVar4 != '\0');
  pcVar3 = in_ECX;
  pcVar5 = in_EDX;
  if (pcVar4[-1] == '/') {
LAB_007341c9:
    pcVar3 = in_ECX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    if (pcVar4[-1] == '\\') goto LAB_007341c9;
    pcVar3 = in_ECX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
    FUN_00401fc0(&DAT_00bed1e4,1);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00401fc0(in_EDX,(int)pcVar5 - (int)(in_EDX + 1));
LAB_00734204:
  local_58 = local_38;
  local_5c = `long___cdecl_Graphics::GetImageInfoFromFile(char_const*,_D3DXIMAGE_INFO*)'::__l2::
             GetImageInfoFromFileBox::vftable;
  FUN_00737d40(uVar2);
  FUN_006edb10("TYPE: %d",local_28);
  if (local_28 == 0x19) {
    local_28 = 0x17;
  }
  puVar7 = local_38;
  puVar9 = (undefined4 *)(local_60 + 0xc);
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  ppppuVar8 = (undefined4 ****)local_54[0];
  if (local_40 < 0x10) {
    ppppuVar8 = local_54;
  }
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c._0_1_ = 1;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_c = (uint)local_c._1_3_ << 8;
  }
  iVar6 = FUN_00737f40(ppppuVar8,0xffffffff,0,local_60 + 0x44);
  if (iVar6 < 0) {
    FUN_006edb10("Texture: Load() Failed");
    FUN_00733f90(iVar6,0);
    if (0xf < local_40) {
      FUN_0089120c(local_54[0]);
    }
  }
  else if (0xf < local_40) {
    FUN_0089120c(local_54[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

