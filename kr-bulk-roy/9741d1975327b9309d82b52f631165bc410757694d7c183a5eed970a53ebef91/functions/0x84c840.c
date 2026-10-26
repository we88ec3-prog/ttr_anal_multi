
uint FUN_0084c840(void)

{
  int *piVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *in_EDX;
  uint uVar5;
  int *piVar6;
  uint local_c;
  int *local_8;
  
  local_8 = (int *)*in_EAX;
  uVar2 = in_EAX[1] - (int)local_8 >> 4;
  local_c = 0;
  if (uVar2 != 0) {
    uVar3 = in_EDX[1] - *in_EDX >> 2;
    do {
      uVar5 = 0;
      if (uVar3 == 0) {
        return local_c;
      }
      piVar1 = (int *)local_8[1];
      piVar6 = (int *)*in_EDX;
      while (piVar4 = (int *)*local_8, (int *)*local_8 != piVar1) {
        while (*piVar4 != *piVar6) {
          piVar4 = piVar4 + 1;
          if (piVar4 == piVar1) goto LAB_0084c89b;
        }
        if (piVar4 == piVar1) break;
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 1;
        if (uVar3 <= uVar5) {
          return local_c;
        }
      }
LAB_0084c89b:
      local_8 = local_8 + 4;
      local_c = local_c + 1;
    } while (local_c < uVar2);
  }
  return 0xffffffff;
}

