
int FUN_00854370(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint3 uVar3;
  
  do {
    if (param_1 == param_2) {
LAB_008543af:
      if (param_3 == param_4) {
        return 0;
      }
      return 1;
    }
    if (param_3 == param_4) {
      if (param_1 != param_2) {
        return 0;
      }
      goto LAB_008543af;
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    uVar2 = *(uint *)(param_3 + 0xc);
    uVar3 = (uint3)(uVar1 >> 8);
    if (uVar2 >= uVar1 && uVar2 != uVar1) {
      return CONCAT31(uVar3,1);
    }
    if (uVar2 < uVar1) {
      return (uint)uVar3 << 8;
    }
    FUN_0079c460();
    FUN_0079c460();
  } while( true );
}

