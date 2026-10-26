
void FUN_007be6a0(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009047c3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CFieldPanel::vftable;
  local_8 = 1;
  uVar2 = 0;
  if ((int)(param_1[6] - param_1[5]) >> 2 != 0) {
    do {
      if (*(int *)(param_1[5] + uVar2 * 4) != 0) {
        FUN_0089120c(*(undefined4 *)(param_1[5] + uVar2 * 4),uVar1);
        *(undefined4 *)(param_1[5] + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)((int)(param_1[6] - param_1[5]) >> 2));
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  if (param_1[3] != 0) {
    FUN_0089120c(param_1[3],uVar1);
    param_1[3] = 0;
  }
  if (param_1[5] != 0) {
    FUN_0089120c(param_1[5],uVar1);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *param_1 = IS3D::IRenderable::vftable;
  ExceptionList = local_10;
  return;
}

