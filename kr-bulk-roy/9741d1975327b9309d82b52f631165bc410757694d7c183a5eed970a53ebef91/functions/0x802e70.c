
void FUN_00802e70(void)

{
  int iVar1;
  void *_Dst;
  undefined4 *in_ECX;
  uint uVar2;
  uint uVar3;
  
  *in_ECX = IS3D::CStaticMesh::vftable;
  uVar3 = 0;
  uVar2 = (int)(in_ECX[3] - in_ECX[2]) >> 2;
  if (uVar2 != 0) {
    do {
      if (*(int *)(in_ECX[2] + uVar3 * 4) != 0) {
        iVar1 = *(int *)(in_ECX[2] + uVar3 * 4);
        if (iVar1 != 0) {
          if (*(int *)(iVar1 + 4) != 0) {
            FUN_00891d3d(*(int *)(iVar1 + 4));
            *(undefined4 *)(iVar1 + 4) = 0;
          }
          if (*(int *)(iVar1 + 8) != 0) {
            FUN_00891d3d(*(int *)(iVar1 + 8));
            *(undefined4 *)(iVar1 + 8) = 0;
          }
          FUN_0089120c(iVar1);
        }
        *(undefined4 *)(in_ECX[2] + uVar3 * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  _Dst = (void *)in_ECX[2];
  if (_Dst != (void *)in_ECX[3]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[3],0);
    in_ECX[3] = _Dst;
  }
  if (in_ECX[2] != 0) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}

