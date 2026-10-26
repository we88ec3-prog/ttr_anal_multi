
int * FUN_0077fca0(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009057a1;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    local_8 = 1;
    if (param_3 != (int *)0x0) {
      piVar1 = (int *)*param_1;
      *param_3 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 8))();
        if (iVar2 == 0) {
          iVar2 = (**(code **)(*(int *)*param_3 + 0xc))();
          *param_3 = iVar2;
        }
        *(int *)(*param_3 + 4) = *(int *)(*param_3 + 4) + 1;
      }
    }
    param_3 = param_3 + 1;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}

