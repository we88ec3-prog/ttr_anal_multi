
void FUN_007bf8a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_114 [4];
  char local_110 [260];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_004dd400(in_ECX,local_114,&param_1);
  if (*piVar1 == *(int *)(in_ECX + 4)) {
    uVar3 = param_1;
    uVar4 = param_2;
    uVar5 = param_3;
    uVar2 = FUN_006d74f0();
    FUN_007c0b70(in_ECX,uVar2);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc,extraout_EDX,uVar3,uVar4,uVar5);
    return;
  }
  _sprintf(local_110,"ITEM UID %d Confilict!\n",param_1,param_2);
  MessageBoxA((HWND)0x0,local_110,"Error",0);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

