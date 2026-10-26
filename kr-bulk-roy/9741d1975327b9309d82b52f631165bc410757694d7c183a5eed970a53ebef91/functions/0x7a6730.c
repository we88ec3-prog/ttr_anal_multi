
void FUN_007a6730(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  float local_8;
  
  *(undefined4 *)(unaff_ESI + 0xcc) = 0;
  *(undefined4 *)(unaff_ESI + 0xe0) = 0;
  *(undefined4 *)(unaff_ESI + 0xd8) = 0;
  *(undefined4 *)(unaff_ESI + 0xdc) = 0;
  *(undefined4 *)(unaff_ESI + 0xb4) = 0;
  local_8 = 0.0;
  *(undefined4 *)(unaff_ESI + 0x11c) = 0;
  if (*(float *)(unaff_ESI + 0xb8) < 0.0) {
    local_8 = *(float *)(unaff_ESI + 0xb8);
  }
  *(float *)(unaff_ESI + 0xb4) = local_8;
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    if (*(int **)(unaff_ESI + 0xac) != (int *)0x0) {
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0xac) + 4))();
      if (iVar2 == 1) {
        fVar1 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0xac) + 0xc0) + 8);
        local_8 = 0.0;
        if ((0.0 <= fVar1) && (local_8 = fVar1, *(float *)(unaff_ESI + 0xb8) < fVar1)) {
          local_8 = *(float *)(unaff_ESI + 0xb8);
        }
        *(float *)(unaff_ESI + 0xb4) = local_8;
      }
      (**(code **)(**(int **)(unaff_ESI + 0xac) + 0x20))
                (*(undefined4 *)(unaff_ESI + 0x1c),*(undefined4 *)(unaff_ESI + 0xb4));
    }
    if (*(int *)(unaff_ESI + 0x108) != 0) {
      *(undefined4 *)(*(int *)(unaff_ESI + 0x108) + 0x1c) = 0;
      FUN_007be5b0();
      return;
    }
  }
  return;
}

