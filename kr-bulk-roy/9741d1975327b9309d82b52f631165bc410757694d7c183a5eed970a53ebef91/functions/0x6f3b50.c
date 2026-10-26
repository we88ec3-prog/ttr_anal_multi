
void FUN_006f3b50(int *param_1,ushort ****param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  ushort ****ppppuVar4;
  undefined1 local_2c [4];
  ushort ***local_28;
  ushort ***local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28 = (ushort ***)param_2;
  *(int **)(in_ECX + 4) = param_1;
  *(undefined4 *)(in_ECX + 0x1120) = 0;
  *(undefined4 *)(in_ECX + 0x111c) = 0;
  *(undefined4 *)(in_ECX + 0x1128) = 0;
  _memset((void *)(in_ECX + 0xc),0,0x110);
  iVar2 = (**(code **)(*param_1 + 0x10))(param_1,4,FUN_006f3ab0);
  if (-1 < iVar2) {
    piVar1 = *(int **)(in_ECX + 8);
    if (piVar1 == (int *)0x0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,&DAT_00bd6b9c);
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x34))(*(int **)(in_ECX + 8),local_28,6),
       -1 < iVar2)) {
      *(undefined4 *)(in_ECX + 0x1128) = 1;
      FUN_00402250(in_ECX + 0x11c);
      ppppuVar4 = (ushort ****)local_24[0];
      if (local_10 < 8) {
        ppppuVar4 = local_24;
      }
      puVar3 = (undefined4 *)FUN_004d7de0(local_2c);
      local_28 = (ushort ***)*puVar3;
      if (ppppuVar4 != (ushort ****)local_28) {
        do {
          iVar2 = _toupper((uint)*(ushort *)ppppuVar4);
          *(ushort *)ppppuVar4 = (ushort)iVar2;
          ppppuVar4 = (ushort ****)((int)ppppuVar4 + 2);
        } while (ppppuVar4 != (ushort ****)local_28);
      }
      iVar2 = FUN_00466df0(local_24,L"XBOX",4);
      *(uint *)(in_ECX + 0x112c) = (uint)(iVar2 != -1);
      FUN_004fa440();
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

