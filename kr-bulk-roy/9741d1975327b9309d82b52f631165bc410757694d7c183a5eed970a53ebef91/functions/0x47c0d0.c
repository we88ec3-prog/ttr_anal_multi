
void FUN_0047c0d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dd30;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  local_8 = 0;
  puVar1 = (undefined4 *)FUN_00891268(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 1;
    puVar1[2] = 1;
    *puVar1 = std::tr1::_Ref_count<IS3D::PreloadSpec>::vftable;
    puVar1[3] = param_2;
  }
  FUN_007a31c0(param_2,puVar1);
  *unaff_FS_OFFSET = local_10;
  return;
}

