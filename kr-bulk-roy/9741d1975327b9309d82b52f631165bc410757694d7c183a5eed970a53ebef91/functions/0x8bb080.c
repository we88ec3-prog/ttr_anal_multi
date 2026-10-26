
undefined4 * FUN_008bb080(undefined4 *param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = param_2;
  *param_3 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x21;
  }
  if (param_2 == (uint *)0x0) {
    return (undefined4 *)0x6;
  }
  uVar1 = *param_1;
  uVar4 = FUN_008baee0(uVar1,0x28,&param_1);
  if (param_1 == (undefined4 *)0x0) {
    *(undefined4 *)(uVar4 + 0x1c) = uVar1;
    uVar2 = *puVar3;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 4) == 0) {
        if (((uVar2 & 2) != 0) && (puVar3[4] != 0)) {
          FUN_008b9f80(uVar1,uVar4);
          uVar4 = puVar3[4];
          *(undefined4 *)(uVar4 + 0x1c) = uVar1;
          *param_3 = uVar4;
          return param_1;
        }
        param_1 = (undefined4 *)0x6;
LAB_008bb10b:
        FUN_008b9f80(uVar1,uVar4);
        *param_3 = 0;
        return param_1;
      }
      param_1 = (undefined4 *)FUN_008bdc30(uVar4,puVar3[3]);
      *(uint *)(uVar4 + 0x10) = puVar3[3];
      if (param_1 != (undefined4 *)0x0) goto LAB_008bb10b;
    }
    else {
      FUN_008b9790(uVar4,puVar3[1],puVar3[2]);
    }
    *(undefined4 *)(uVar4 + 0x1c) = uVar1;
    *param_3 = uVar4;
  }
  return param_1;
}

