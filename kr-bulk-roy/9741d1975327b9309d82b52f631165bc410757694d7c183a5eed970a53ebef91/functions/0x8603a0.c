
undefined4 FUN_008603a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int unaff_EDI;
  int *piVar4;
  int iStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 local_18 [5];
  
  iStack_2c = param_1;
  uStack_30 = 0x8603b7;
  FUN_007802f0();
  piStack_34 = (int *)(in_ECX + 0x54);
  if (piStack_34 != (int *)0x0) {
    iStack_2c = 0;
    uStack_30 = 0x1c;
    iStack_38 = *(int *)(param_1 + 0x88);
    FUN_00721910();
  }
  iStack_38 = *(int *)(param_1 + 0x88);
  local_18[0] = *(undefined4 *)(in_ECX + 0x74);
  iStack_2c = 0;
  uStack_30 = 4;
  piStack_34 = local_18;
  FUN_00721910();
  if (unaff_EDI != 0) {
    FUN_007bb350();
  }
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffffe0,4,0);
  piVar4 = *(int **)(in_ECX + 0x98);
  piVar1 = *(int **)(in_ECX + 0x9c);
  do {
    if (piVar4 == piVar1) {
      return 1;
    }
    iStack_38 = *piVar4;
    piStack_34 = piVar4;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_38,4,0);
    if (iStack_38 != 0) {
      piVar2 = *(int **)(param_1 + 0x18);
      if (&iStack_38 < piVar2) {
        piVar3 = *(int **)(param_1 + 0x14);
        if (&iStack_38 < piVar3) goto LAB_008604a1;
        if (piVar2 == *(int **)(param_1 + 0x1c)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x18) =
               *(undefined4 *)(*(int *)(param_1 + 0x14) + ((int)&iStack_38 - (int)piVar3 >> 2) * 4);
        }
      }
      else {
LAB_008604a1:
        if (piVar2 == *(int **)(param_1 + 0x1c)) {
          FUN_00797930();
        }
        piStack_34 = piVar4;
        if (*(int **)(param_1 + 0x18) != (int *)0x0) {
          **(int **)(param_1 + 0x18) = iStack_38;
        }
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
      piVar4 = piStack_34;
    }
    piVar4 = piVar4 + 1;
  } while( true );
}

