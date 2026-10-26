
uint FUN_008ecef0(undefined2 *param_1)

{
  undefined2 uVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  uint in_ECX;
  
  if (((int)((in_ECX ^ (int)in_ECX >> 0x1f) - ((int)in_ECX >> 0x1f)) < 0x4000) &&
     (uVar2 = (in_EAX ^ (int)in_EAX >> 0x1f) - ((int)in_EAX >> 0x1f), (int)uVar2 < 0x4000)) {
    if ((in_ECX == 0) && (in_EAX == 0)) goto LAB_008ecf4e;
    in_ECX = in_ECX << 0xe;
    in_EAX = in_EAX << 0xe;
  }
  iVar3 = FUN_008ba200(in_ECX,in_EAX);
  uVar1 = FUN_008b7f40(in_ECX,iVar3 * 4);
  *param_1 = uVar1;
  uVar2 = FUN_008b7f40(in_EAX,iVar3 * 4);
  param_1[1] = (short)uVar2;
LAB_008ecf4e:
  return uVar2 & 0xffffff00;
}

