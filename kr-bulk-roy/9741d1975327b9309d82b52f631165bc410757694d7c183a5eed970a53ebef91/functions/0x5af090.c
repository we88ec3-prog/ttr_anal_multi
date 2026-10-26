
undefined4 FUN_005af090(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (param_1 < 0x2afc) {
    if (param_1 == 0x2afb) {
      piVar1 = (int *)FUN_0040f060();
      if ((*(int *)(*piVar1 + 0x5ef8) != 0) ||
         (iVar2 = FUN_00404ba0(), *(int *)(iVar2 + 0x5f4c) == 6)) {
        iVar2 = **(int **)(in_ECX + 0x23c);
        if (((uint)(*(int **)(in_ECX + 0x23c))[10] >> 8 & 1) != 0) {
          (**(code **)(iVar2 + 0xd4))();
          return 1;
        }
        (**(code **)(iVar2 + 0xd0))();
      }
      return 1;
    }
    switch(param_1) {
    case 0x2904:
    case 0x2905:
    case 0x2906:
    case 0x2907:
    case 0x2908:
    case 0x2909:
    case 0x290a:
    case 0x290d:
    case 0x290f:
    case 0x2910:
    case 0x2911:
    case 0x2912:
    case 0x2913:
    case 0x2915:
    case 0x2919:
    case 0x291a:
      return 1;
    }
  }
  uVar3 = FUN_0059cc50(param_1);
  return uVar3;
}

