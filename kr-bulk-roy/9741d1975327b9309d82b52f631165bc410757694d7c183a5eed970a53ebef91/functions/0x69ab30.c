
void FUN_0069ab30(void)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  int in_EAX;
  
  _Dst = *(void **)(in_EAX + 0x164);
  if (_Dst != *(void **)(in_EAX + 0x168)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_EAX + 0x168),0);
    *(void **)(in_EAX + 0x168) = _Dst;
  }
  *(undefined4 *)(in_EAX + 0xd8) = 1;
  FUN_0069bb20();
  iVar2 = DAT_00fb1318;
  iVar1 = *(int *)(DAT_00fb1318 + 0xbfe8);
  *(undefined4 *)(iVar1 + 0x78) = 1;
  *(undefined1 *)(iVar1 + 0x80) = 1;
  *(undefined4 *)(*(int *)(iVar2 + 0xbfe8) + 0x7c) = 0x42340000;
  FUN_006999f0(in_EAX);
  FUN_0069a050(in_EAX);
  return;
}

