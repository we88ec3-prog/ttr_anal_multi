
void FUN_0083a130(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  undefined1 local_8 [4];
  
  FUN_0083f0d0(in_ECX + 0x3b0,local_8,*(undefined4 *)(in_ECX + 0x3b0),
               *(undefined4 *)(in_ECX + 0x3b4));
  FUN_0083f200(*(undefined4 *)(*(int *)(in_ECX + 0x3e4) + 4));
  *(int *)(*(int *)(in_ECX + 0x3e4) + 4) = *(int *)(in_ECX + 0x3e4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3e4) = *(undefined4 *)(in_ECX + 0x3e4);
  *(int *)(*(int *)(in_ECX + 0x3e4) + 8) = *(int *)(in_ECX + 0x3e4);
  *(undefined4 *)(in_ECX + 1000) = 0;
  FUN_0083f200(*(undefined4 *)(*(int *)(in_ECX + 0x3d4) + 4));
  *(int *)(*(int *)(in_ECX + 0x3d4) + 4) = *(int *)(in_ECX + 0x3d4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3d4) = *(undefined4 *)(in_ECX + 0x3d4);
  *(int *)(*(int *)(in_ECX + 0x3d4) + 8) = *(int *)(in_ECX + 0x3d4);
  *(undefined4 *)(in_ECX + 0x3d8) = 0;
  FUN_0083f200(*(undefined4 *)(*(int *)(in_ECX + 0x3c4) + 4));
  *(int *)(*(int *)(in_ECX + 0x3c4) + 4) = *(int *)(in_ECX + 0x3c4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x3c4) = *(undefined4 *)(in_ECX + 0x3c4);
  *(int *)(*(int *)(in_ECX + 0x3c4) + 8) = *(int *)(in_ECX + 0x3c4);
  *(undefined4 *)(in_ECX + 0x3c8) = 0;
  FUN_0083ee90(in_ECX + 0x464);
  piVar1 = *(int **)(in_ECX + 0x43c);
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*(int *)(in_ECX + 0x43c) + 4) = *(int *)(in_ECX + 0x43c);
  *(undefined4 *)(in_ECX + 0x440) = 0;
  if (piVar2 != *(int **)(in_ECX + 0x43c)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(in_ECX + 0x43c));
  }
  return;
}

