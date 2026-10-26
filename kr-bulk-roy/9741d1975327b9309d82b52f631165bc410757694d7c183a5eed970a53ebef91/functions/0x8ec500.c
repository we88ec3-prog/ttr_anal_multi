
int FUN_008ec500(void)

{
  longlong lVar1;
  int in_EAX;
  int iVar2;
  
  iVar2 = FUN_008ec480();
  lVar1 = (longlong)(int)(uint)*(ushort *)(in_EAX + 0xfc) * (longlong)iVar2;
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  return ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
}

