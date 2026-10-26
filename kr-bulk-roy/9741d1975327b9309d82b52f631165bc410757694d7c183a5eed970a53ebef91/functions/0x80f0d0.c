
void FUN_0080f0d0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904698;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = MoonSound::CWAVLoader::vftable;
  local_8 = 0;
  if (param_1[2] != 0) {
    iVar1 = *(int *)(param_1[2] + 0x2c);
    if (iVar1 != 0) {
      FUN_00891d3d(iVar1,uVar2);
    }
    if (*(int **)(param_1[2] + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1[2] + 0x34) + 4))();
    }
    FUN_0089120c(param_1[2]);
    param_1[2] = 0;
  }
  *param_1 = MoonSound::SoundLoader::vftable;
  ExceptionList = local_10;
  return;
}

