
void FUN_008e0180(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *in_EAX;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x290);
  _memset(in_EAX,0,0x3a4);
  FUN_008e00a0(param_2,param_3);
  *(int *)((int)in_EAX + 0x4c) = iVar1;
  *(undefined4 *)((int)in_EAX + 0x37c) = *(undefined4 *)(iVar1 + 0x5c);
  *(undefined4 *)((int)in_EAX + 0x38c) = *(undefined4 *)(iVar1 + 0x51c);
  uVar2 = FUN_008e0150(*(undefined4 *)(iVar1 + 0x558));
  *(undefined4 *)((int)in_EAX + 900) = uVar2;
  *(undefined4 *)((int)in_EAX + 0x398) = param_4;
  return;
}

