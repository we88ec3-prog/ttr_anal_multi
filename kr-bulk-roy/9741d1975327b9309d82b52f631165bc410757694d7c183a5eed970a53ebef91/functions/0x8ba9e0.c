
void FUN_008ba9e0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 int *param_6)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = param_4 - (int)param_6;
  ppuVar2 = &PTR_FUN_00bd6dd8;
  do {
    puVar4 = (undefined4 *)(iVar3 + (int)param_6);
    *puVar4 = 0;
    if (param_2 == 0) {
      *param_6 = 0;
LAB_008baa29:
      iVar1 = (*(code *)*ppuVar2)(param_1,param_2,param_3,puVar4,(int)puVar4 + (param_5 - param_4));
      *param_6 = iVar1;
    }
    else {
      iVar1 = FUN_008b97e0(param_2,0);
      *param_6 = iVar1;
      if (iVar1 == 0) goto LAB_008baa29;
    }
    ppuVar2 = ppuVar2 + 2;
    param_6 = param_6 + 1;
    if (0xbd6e1f < (int)ppuVar2) {
      return;
    }
  } while( true );
}

