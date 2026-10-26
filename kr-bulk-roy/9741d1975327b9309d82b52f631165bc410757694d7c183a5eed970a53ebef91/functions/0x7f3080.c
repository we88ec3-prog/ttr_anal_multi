
void FUN_007f3080(uint param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint in_ECX;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009348ce;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_ESI[10] = in_ECX / 6;
  *unaff_ESI = IS3D::CStaticMeshDrawCache::vftable;
  unaff_ESI[3] = 0x112;
  unaff_ESI[4] = 0x20;
  unaff_ESI[5] = in_ECX;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = param_1;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = param_1 / 6;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  unaff_ESI[1] = 0;
  iVar3 = (**(code **)(*piVar2 + 0x68))(piVar2,in_ECX << 5,0x208,unaff_ESI[3],0,unaff_ESI + 1,0);
  if (iVar3 != 0) {
    MessageBoxA((HWND)0x0,"CStaticMeshDrawCache VertexBuffer Create FAILED","Error",0);
  }
  unaff_ESI[2] = 0;
  iVar3 = (**(code **)(*piVar2 + 0x6c))(piVar2,param_1 * 2,0x208,0x65,0,unaff_ESI + 2,0);
  if (iVar3 != 0) {
    MessageBoxA((HWND)0x0,"CStaticMeshDrawCache IndexBuffer Create FAILED","Error",0);
  }
  ExceptionList = local_10;
  return;
}

