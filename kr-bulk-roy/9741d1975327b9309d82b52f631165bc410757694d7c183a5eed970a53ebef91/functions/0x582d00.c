
void FUN_00582d00(void)

{
  int *piVar1;
  double dVar2;
  undefined4 *in_EAX;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  void *_Str;
  uint uVar6;
  FILE *_File;
  int iVar7;
  byte bVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  undefined2 in_FPUControlWord;
  uint local_1c;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  local_c = ((int)(in_EAX[8] - in_EAX[7]) / 0x1c) * 0x28 + 0x34;
  pcVar3 = (char *)FUN_0087dc3d(local_c);
  pcVar4 = pcVar3;
  for (iVar7 = local_c; iVar7 != 0; iVar7 = iVar7 + -1) {
    *pcVar4 = '\0';
    pcVar4 = pcVar4 + 1;
  }
  *(undefined4 *)pcVar3 = s_Sequence____00f7fc44._0_4_;
  *(undefined4 *)(pcVar3 + 4) = s_Sequence____00f7fc44._4_4_;
  *(undefined4 *)(pcVar3 + 8) = s_Sequence____00f7fc44._8_4_;
  puVar5 = in_EAX;
  if (7 < (uint)in_EAX[5]) {
    puVar5 = (undefined4 *)*in_EAX;
  }
  FID_conflict__memcpy(pcVar3 + 0xc,puVar5,in_EAX[4] * 2);
  iVar7 = (int)(in_EAX[8] - in_EAX[7]) >> 0x1f;
  uVar11 = 0;
  if ((int)(in_EAX[8] - in_EAX[7]) / 0x1c + iVar7 != iVar7) {
    local_8 = 0;
    pcVar4 = pcVar3 + 0x34;
    do {
      puVar5 = (undefined4 *)(local_8 + in_EAX[7]);
      piVar1 = puVar5 + 4;
      if (7 < (uint)puVar5[5]) {
        puVar5 = (undefined4 *)*puVar5;
      }
      FID_conflict__memcpy(pcVar4,puVar5,*piVar1 * 2);
      local_8 = local_8 + 0x1c;
      uVar11 = uVar11 + 1;
      pcVar4 = pcVar4 + 0x28;
    } while (uVar11 < (uint)((int)(in_EAX[8] - in_EAX[7]) / 0x1c));
  }
  dVar2 = (double)local_c;
  if (local_c < 0) {
    dVar2 = dVar2 + 4294967296.0;
  }
  local_8 = CONCAT22(in_FPUControlWord,(undefined2)local_8);
  local_1c = (uint)(longlong)ROUND(dVar2 * 1.2);
  local_10 = local_1c;
  _Str = (void *)FUN_0087dc3d(local_1c);
  FUN_00727220(_Str,&local_10);
  FUN_00891d3d(pcVar3);
  uVar11 = local_10;
  uVar6 = 0;
  local_8 = 0;
  if (in_EAX[4] != 0) {
    uVar10 = 0;
    do {
      puVar5 = in_EAX;
      if (7 < (uint)in_EAX[5]) {
        puVar5 = (undefined4 *)*in_EAX;
      }
      uVar10 = uVar10 + *(short *)((int)puVar5 + uVar6 * 2);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)in_EAX[4]);
    local_8 = (uint)uVar10;
  }
  uVar9 = (int)local_8 >> 8;
  uVar6 = 0;
  bVar8 = (byte)local_8;
  if (local_10 != 0) {
    do {
      *(byte *)(uVar6 + (int)_Str) = *(byte *)(uVar6 + (int)_Str) ^ bVar8;
      bVar8 = (byte)uVar9;
      uVar9 = (uint)*(byte *)(uVar6 + (int)_Str);
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_10);
  }
  _File = _fopen("whsprcac.dat","wb");
  if (_File != (FILE *)0x0) {
    _fwrite(_Str,uVar11,1,_File);
    _fwrite(&local_c,4,1,_File);
    _fclose(_File);
  }
  FUN_00891d3d(_Str);
  return;
}

