
undefined4 *
FUN_008bcef0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5,char param_6
            ,int *param_7,size_t *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  void *_Base;
  int iVar8;
  int *piVar9;
  size_t *psVar10;
  int local_c;
  
  uVar2 = param_2;
  uVar1 = *param_1;
  param_1 = (undefined4 *)FUN_008b97e0(param_2,param_3);
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = FUN_008b9ab0(uVar2,&param_1);
    if (param_1 == (undefined4 *)0x0) {
      local_c = (int)param_1;
      if ((uVar4 & 0xffff) != 0xffffffff) {
        do {
          iVar5 = FUN_008b9c00(uVar2,&param_1);
          if (param_1 != (undefined4 *)0x0) {
            return (undefined4 *)(int)param_1;
          }
          uVar6 = FUN_008b9ab0(uVar2,&param_1);
          if (param_1 != (undefined4 *)0x0) {
            return (undefined4 *)(int)param_1;
          }
          uVar7 = FUN_008b9ab0(uVar2,&param_1);
          psVar10 = param_8;
          if (param_1 != (undefined4 *)0x0) {
            return (undefined4 *)(int)param_1;
          }
          if (iVar5 == param_5) {
            *param_8 = (uVar6 & 0xffff) + 1;
            param_1 = (undefined4 *)FUN_008b97e0(uVar2,(uVar7 & 0xffff) + param_3);
            if (param_1 != (undefined4 *)0x0) {
              return (undefined4 *)(int)param_1;
            }
            _Base = (void *)FUN_008bc7d0(uVar1,8,0,*psVar10,0,&param_1);
            if (param_1 != (undefined4 *)0x0) {
              return (undefined4 *)(int)param_1;
            }
            local_c = (int)param_1;
            if ((int)*psVar10 < 1) goto LAB_008bd07d;
            goto LAB_008bcff0;
          }
          local_c = local_c + 1;
        } while (local_c < (int)((uVar4 & 0xffff) + 1));
      }
      param_1 = (undefined4 *)0x1;
    }
  }
  return param_1;
  while( true ) {
    *(uint *)((int)_Base + local_c * 8 + 4) = uVar4 & 0xffffff;
    local_c = local_c + 1;
    psVar10 = param_8;
    if ((int)*param_8 <= local_c) break;
LAB_008bcff0:
    uVar3 = FUN_008b9ab0(uVar2,&param_1);
    *(undefined2 *)((int)_Base + local_c * 8) = uVar3;
    iVar5 = (int)param_1;
    if ((((param_1 != (undefined4 *)0x0) ||
         (param_1 = (undefined4 *)FUN_008b9820(uVar2,2), iVar5 = (int)param_1,
         param_1 != (undefined4 *)0x0)) ||
        (uVar4 = FUN_008b9c00(uVar2,&param_1), iVar5 = (int)param_1, param_1 != (undefined4 *)0x0))
       || (param_1 = (undefined4 *)FUN_008b9820(uVar2,4), iVar5 = (int)param_1,
          param_1 != (undefined4 *)0x0)) goto LAB_008bd0de;
  }
LAB_008bd07d:
  if (param_6 != '\0') {
    _qsort(_Base,*psVar10,8,FUN_008b9740);
  }
  iVar8 = FUN_008bc7d0(uVar1,4,0,*psVar10,0,&param_1);
  iVar5 = (int)param_1;
  if (param_1 == (undefined4 *)0x0) {
    iVar5 = 0;
    if (0 < (int)*psVar10) {
      piVar9 = (int *)((int)_Base + 4);
      do {
        *(int *)(iVar8 + iVar5 * 4) = *piVar9 + param_4;
        iVar5 = iVar5 + 1;
        piVar9 = piVar9 + 2;
      } while (iVar5 < (int)*psVar10);
    }
    *param_7 = iVar8;
    iVar5 = 0;
  }
LAB_008bd0de:
  FUN_008b9f80(uVar1,_Base);
  return (undefined4 *)iVar5;
}

