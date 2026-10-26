
int FUN_008fcb60(int param_1,uint param_2)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(in_ECX + 0x10b8);
  if (in_EAX < uVar3) {
    if ((*(int *)(in_ECX + 0x10bc) - in_ECX) - 0xb8U < uVar3 - in_EAX) {
      iVar2 = FUN_008fca70();
      if (iVar2 != 0) {
        return 0;
      }
    }
    else {
      *(uint *)(in_ECX + 0x10bc) = (*(int *)(in_ECX + 0x10bc) - uVar3) + in_EAX;
      *(uint *)(in_ECX + 0x10b8) = in_EAX;
    }
  }
  iVar2 = 0;
  if (((in_EAX <= *(uint *)(in_ECX + 0x10b8)) || (iVar1 = FUN_008fcaf0(), iVar1 == 0)) &&
     (param_2 != 0)) {
    while( true ) {
      uVar3 = *(int *)(in_ECX + 0x10c0) - (int)*(void **)(in_ECX + 0x10bc);
      if (param_2 <= uVar3) {
        uVar3 = param_2;
      }
      FID_conflict__memcpy((void *)(iVar2 + param_1),*(void **)(in_ECX + 0x10bc),uVar3);
      *(int *)(in_ECX + 0x10bc) = *(int *)(in_ECX + 0x10bc) + uVar3;
      *(int *)(in_ECX + 0x10b8) = *(int *)(in_ECX + 0x10b8) + uVar3;
      iVar2 = iVar2 + uVar3;
      param_2 = param_2 - uVar3;
      if (param_2 == 0) break;
      iVar1 = FUN_008fcab0();
      if (iVar1 != 0) {
        return iVar2;
      }
    }
  }
  return iVar2;
}

