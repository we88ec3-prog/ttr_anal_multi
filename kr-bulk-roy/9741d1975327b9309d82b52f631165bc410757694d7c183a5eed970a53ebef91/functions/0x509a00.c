
uint FUN_00509a00(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_EDX;
  int *piVar3;
  int iVar4;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar4 = 1;
  piVar3 = (int *)(in_EDX + 0x1724);
  piVar1 = param_2;
  do {
    if ((iVar4 == 1) && (piVar1 = piVar3 + -0xb, piVar1 != (int *)0x0)) {
      piVar1 = (int *)0x1;
      piVar2 = piVar3;
      if (0 < piVar3[0x31d]) {
        do {
          if (*piVar2 == param_1) {
            if (piVar1 != (int *)0x0) {
              *param_2 = 1;
              *param_3 = piVar1;
              return CONCAT31((int3)((uint)piVar1 >> 8),1);
            }
            break;
          }
          piVar1 = (int *)((int)piVar1 + 1);
          piVar2 = piVar2 + 8;
        } while ((int)piVar1 <= piVar3[0x31d]);
      }
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 0x32a;
    if (1 < iVar4) {
      return (uint)piVar1 & 0xffffff00;
    }
  } while( true );
}

