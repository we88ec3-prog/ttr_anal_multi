
uint FUN_00729460(undefined4 param_1)

{
  bool bVar1;
  int in_EAX;
  size_t sVar2;
  int iVar3;
  size_t _Count;
  
  bVar1 = false;
  if ((in_EAX == 0) || (*(char *)(in_EAX + 0x5c) != 'w')) {
    return 0xfffffffe;
  }
  *(undefined4 *)(in_EAX + 4) = 0;
  do {
    _Count = 0x4000 - *(int *)(in_EAX + 0x10);
    if (_Count != 0) {
      sVar2 = _fwrite(*(void **)(in_EAX + 0x48),1,_Count,*(FILE **)(in_EAX + 0x40));
      if (sVar2 != _Count) {
        *(undefined4 *)(in_EAX + 0x38) = 0xffffffff;
        return 0xffffffff;
      }
      *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(in_EAX + 0x48);
      *(undefined4 *)(in_EAX + 0x10) = 0x4000;
    }
    if (bVar1) break;
    *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x68) + *(int *)(in_EAX + 0x10);
    iVar3 = FUN_00729a20(param_1);
    *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x68) - *(int *)(in_EAX + 0x10);
    *(int *)(in_EAX + 0x38) = iVar3;
    if ((_Count == 0) && (iVar3 == -5)) {
      *(undefined4 *)(in_EAX + 0x38) = 0;
    }
    if ((*(int *)(in_EAX + 0x10) == 0) && (*(int *)(in_EAX + 0x38) != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  } while ((*(int *)(in_EAX + 0x38) == 0) || (*(int *)(in_EAX + 0x38) == 1));
  return -(uint)(*(uint *)(in_EAX + 0x38) != 1) & *(uint *)(in_EAX + 0x38);
}

