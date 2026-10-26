
void FUN_00542cd0(int *param_1,int param_2,char *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  char local_6c [100];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*param_1 != 0) && (param_2 != 0)) {
    _memset(local_6c,0,0x5c);
    if (param_3 == (char *)0x0) {
      _strcpy_s(local_6c,0x20,"Default");
      pcVar3 = local_6c;
    }
    else {
      FUN_0080df70();
      pcVar3 = param_3;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("Volume");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x24);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 1;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("MinGain");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x28);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 2;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("MaxGain");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x2c);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 4;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("Pitch");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x30);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 8;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("MaxPlaybacks");
    iVar2 = FUN_00542fd0(*puVar1);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x1000;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("MaxPerFilePlaybacks");
    iVar2 = FUN_00542fd0(*puVar1);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x2000;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("ReferenceDistance");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x38);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x20;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("MaxDistance");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x3c);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x40;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("RollOffFactor");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x40);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x80;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("ConeInsideAngle");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x44);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x100;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("ConeOutsideAngle");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x48);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x200;
    }
    puVar1 = (undefined4 *)FUN_0071ba40("ConeOutsideGain");
    iVar2 = FUN_00542f40(*puVar1,pcVar3 + 0x4c);
    if (iVar2 != 0) {
      *(uint *)(pcVar3 + 0x20) = *(uint *)(pcVar3 + 0x20) | 0x400;
    }
    if (param_3 == (char *)0x0) {
      puVar1 = *(undefined4 **)(*param_1 + 0x20);
      for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        puVar1 = puVar1 + 1;
      }
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

