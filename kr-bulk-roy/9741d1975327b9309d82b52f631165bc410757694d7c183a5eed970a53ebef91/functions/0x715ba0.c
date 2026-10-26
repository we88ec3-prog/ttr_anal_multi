
void FUN_00715ba0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = in_ECX;
  if (param_1 != (int *)0x0) goto LAB_00715bb4;
  do {
    param_1 = piVar1;
    if (param_1 == (int *)0x0) {
      return;
    }
LAB_00715bb4:
    iVar2 = (**(code **)(*param_1 + 0x14))();
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*param_1 + 0x14))();
      FUN_00715ba0(uVar3);
    }
    iVar2 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 == 0) {
      for (iVar2 = *(int *)(in_ECX[0x4e] + 0x2c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x28)) {
        if (param_1[0x47] == *(int *)(iVar2 + 0x44)) goto LAB_00715c00;
      }
      iVar2 = 0;
LAB_00715c00:
      (**(code **)(*param_1 + 0x3c))(iVar2);
    }
    piVar1 = (int *)param_1[2];
  } while( true );
}

