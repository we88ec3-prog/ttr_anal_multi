
uint FUN_00713ba0(void *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  size_t sVar3;
  
  sVar3 = param_2 * param_3;
  iVar1 = *(int *)(in_ECX + 8);
  iVar2 = *(int *)(in_ECX + 0x14);
  if (*(uint *)(iVar2 + 0x4c) < iVar1 + sVar3) {
    sVar3 = *(uint *)(iVar2 + 0x4c) - iVar1;
    if ((int)sVar3 < 1) {
      sVar3 = 0;
    }
    else {
      FID_conflict__memcpy(param_1,(void *)(*(int *)(iVar2 + 0x48) + iVar1),sVar3);
    }
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + sVar3;
    *(undefined4 *)(in_ECX + 0x10) = 1;
    return sVar3 / param_2;
  }
  FID_conflict__memcpy(param_1,(void *)(*(int *)(iVar2 + 0x48) + iVar1),sVar3);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + sVar3;
  return param_3;
}

