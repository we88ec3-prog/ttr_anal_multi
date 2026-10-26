
undefined4 * FUN_008569c0(undefined4 *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *_Dst;
  
  FUN_0077fed0(param_1);
  _Dst = param_1 + 0x1c;
  *param_1 = gbTexture::vftable;
  _memset(_Dst,0,0x44);
  param_1[0x2b] = 0x3f800000;
  param_1[0x26] = 0x3f800000;
  param_1[0x21] = 0x3f800000;
  *_Dst = 0x3f800000;
  param_1[0x2e] = 0;
  param_1[0x15] = *(undefined4 *)(in_EAX + 0x54);
  param_1[0x16] = *(undefined4 *)(in_EAX + 0x58);
  param_1[0x17] = *(undefined4 *)(in_EAX + 0x5c);
  param_1[0x18] = *(undefined4 *)(in_EAX + 0x60);
  param_1[0x19] = *(undefined4 *)(in_EAX + 100);
  param_1[0x1a] = *(undefined4 *)(in_EAX + 0x68);
  param_1[0x1b] = *(undefined4 *)(in_EAX + 0x6c);
  param_1[0x2e] = *(undefined4 *)(in_EAX + 0xb8);
  param_1[0x2d] = *(undefined4 *)(in_EAX + 0xb4);
  puVar2 = (undefined4 *)(in_EAX + 0x70);
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *_Dst = *puVar2;
    puVar2 = puVar2 + 1;
    _Dst = _Dst + 1;
  }
  return param_1;
}

