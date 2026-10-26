
void FUN_007299d0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  uint _Size;
  
  _Size = *(uint *)(*(int *)(in_EAX + 0x1c) + 0x14);
  if (*(uint *)(in_EAX + 0x10) < _Size) {
    _Size = *(uint *)(in_EAX + 0x10);
  }
  if (_Size != 0) {
    FID_conflict__memcpy(*(void **)(in_EAX + 0xc),*(void **)(*(int *)(in_EAX + 0x1c) + 0x10),_Size);
    *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + _Size;
    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x10);
    *piVar1 = *piVar1 + _Size;
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + _Size;
    *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) - _Size;
    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x14);
    *piVar1 = *piVar1 - _Size;
    iVar2 = *(int *)(in_EAX + 0x1c);
    if (*(int *)(iVar2 + 0x14) == 0) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
    }
  }
  return;
}

