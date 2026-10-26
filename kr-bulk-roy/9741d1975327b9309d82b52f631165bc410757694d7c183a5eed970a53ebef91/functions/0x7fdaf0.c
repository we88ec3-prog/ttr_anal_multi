
undefined4 * FUN_007fdaf0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x1c) != *(int *)(param_1 + 0x20)) {
    local_c = (undefined4 *)FUN_00891268(0x18);
    uVar4 = 0;
    if (local_c == (undefined4 *)0x0) {
      local_c = (undefined4 *)0x0;
    }
    else {
      *local_c = IS3D::CStaticMesh::vftable;
      local_c[1] = 0;
      local_c[2] = 0;
      local_c[3] = 0;
      local_c[4] = 0;
    }
    uVar5 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2;
    if (uVar5 != 0) {
      do {
        iVar3 = FUN_007f3a70();
        local_8 = iVar3;
        if (iVar3 != 0) {
          piVar1 = (int *)local_c[3];
          if ((&local_8 < piVar1) && (piVar2 = (int *)local_c[2], piVar2 <= &local_8)) {
            if (piVar1 == (int *)local_c[4]) {
              FUN_00797930();
            }
            if ((undefined4 *)local_c[3] != (undefined4 *)0x0) {
              *(undefined4 *)local_c[3] =
                   *(undefined4 *)(local_c[2] + ((int)&local_8 - (int)piVar2 >> 2) * 4);
            }
          }
          else {
            if (piVar1 == (int *)local_c[4]) {
              FUN_00797930();
            }
            if ((int *)local_c[3] != (int *)0x0) {
              *(int *)local_c[3] = iVar3;
            }
          }
          local_c[3] = local_c[3] + 4;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    return local_c;
  }
  return (undefined4 *)0x0;
}

