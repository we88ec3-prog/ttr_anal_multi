
void FUN_007e4ed0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905481;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CFieldGeometry::vftable;
  param_1[1] = IS3D::CFieldGeometry::vftable;
  local_8 = 2;
  piVar1 = (int *)param_1[9];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      FUN_007ffcc0(uVar3);
      if (*piVar1 != 0) {
        FUN_007f7350();
        *piVar1 = 0;
      }
    }
    FUN_0089120c(piVar1);
    param_1[9] = 0;
  }
  if (param_1[0x52] != 0) {
    FUN_00891d3d(param_1[0x52]);
    param_1[0x52] = 0;
  }
  uVar3 = 0;
  if ((int)(param_1[0x62] - param_1[0x61]) >> 2 != 0) {
    do {
      if (*(int *)(param_1[0x61] + uVar3 * 4) != 0) {
        iVar2 = *(int *)(param_1[0x61] + uVar3 * 4);
        if (iVar2 != 0) {
          FUN_007f7770();
          FUN_0089120c(iVar2);
        }
        *(undefined4 *)(param_1[0x61] + uVar3 * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)((int)(param_1[0x62] - param_1[0x61]) >> 2));
  }
  if (param_1[0x60] != 0) {
    FUN_0089120c(param_1[0x60]);
    param_1[0x60] = 0;
  }
  if (param_1[0x5b] != 0) {
    FUN_00891d3d(param_1[0x5b]);
    param_1[0x5b] = 0;
  }
  if (param_1[0x5e] != 0) {
    FUN_00891d3d(param_1[0x5e]);
    param_1[0x5e] = 0;
  }
  if (param_1[0x61] != 0) {
    FUN_0089120c(param_1[0x61]);
  }
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[1] = IS3D::IRenderable::vftable;
  *param_1 = IS3D::CSteppable::vftable;
  ExceptionList = local_10;
  return;
}

