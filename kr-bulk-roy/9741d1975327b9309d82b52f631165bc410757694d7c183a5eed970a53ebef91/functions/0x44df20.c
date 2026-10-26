
uint FUN_0044df20(uint param_1,ushort *param_2,uint param_3)

{
  uint in_EAX;
  uint uVar1;
  ushort *puVar2;
  undefined4 *in_ECX;
  
  if ((uint)in_ECX[4] < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar1 = in_ECX[4] - param_1;
  if (uVar1 < in_EAX) {
    in_EAX = uVar1;
  }
  uVar1 = in_EAX;
  if (param_3 <= in_EAX) {
    uVar1 = param_3;
  }
  if (7 < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  puVar2 = (ushort *)((int)in_ECX + param_1 * 2);
  do {
    if (uVar1 == 0) {
LAB_0044df85:
      if (param_3 <= in_EAX) {
        return (uint)(in_EAX != param_3);
      }
      return 0xffffffff;
    }
    if (*puVar2 != *param_2) {
      uVar1 = (-(uint)(*puVar2 < *param_2) & 0xfffffffe) + 1;
      if (uVar1 != 0) {
        return uVar1;
      }
      goto LAB_0044df85;
    }
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
    uVar1 = uVar1 - 1;
  } while( true );
}

