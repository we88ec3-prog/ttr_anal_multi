
void FUN_008c1ce0(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint _Size;
  ushort *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_4 + 0x3f4) - *(int *)(param_4 + 0x3f0) * param_1;
  if (-1 < *(int *)(param_4 + 0x3f0)) {
    iVar4 = iVar4 + (*(int *)(param_4 + 1000) + -1) * *(int *)(param_4 + 0x3f0);
  }
  if (0 < param_2) {
    puVar3 = (ushort *)(param_3 + 2);
    do {
      bVar1 = (byte)puVar3[1];
      if (bVar1 != 0) {
        _Size = (uint)*puVar3;
        if (_Size < 8) {
          pbVar2 = (byte *)((short)puVar3[-1] + iVar4);
          switch(_Size) {
          case 7:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 6:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 5:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 4:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 3:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 2:
            *pbVar2 = bVar1;
            pbVar2 = pbVar2 + 1;
          case 1:
            *pbVar2 = bVar1;
          }
        }
        else {
          _memset((void *)((short)puVar3[-1] + iVar4),(uint)bVar1,_Size);
        }
      }
      param_2 = param_2 + -1;
      puVar3 = puVar3 + 3;
    } while (0 < param_2);
  }
  return;
}

