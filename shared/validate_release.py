"""Isolated package tests, original source read denial, and corruption detection."""
import hashlib,json,pathlib,re,shutil,subprocess,sys,zipfile
ROOT=pathlib.Path(__file__).resolve().parent.parent
def main():
    results=[]
    for tid in ('T08','T09'):
        zpath=ROOT/'exports'/f'kr-{tid}-release.zip';out=ROOT/'validation'/f'isolated-release-{tid}'
        if out.exists():raise RuntimeError('Isolated test path already exists')
        with zipfile.ZipFile(zpath) as z:
            assert all((out/n).resolve().is_relative_to(out.resolve()) for n in z.namelist());z.extractall(out)
        code="import sys,pathlib,runpy; root=pathlib.Path.cwd(); original=root.parents[2]/'anal'\ndef audit(event,args):\n if event=='open' and isinstance(args[0],(str,bytes)):\n  p=pathlib.Path(args[0]).resolve()\n  if p==original or original in p.parents or p.name=='Tartaros.bin':raise RuntimeError('Original source access forbidden')\nsys.addaudithook(audit)\nsys.argv=['handoff.py']+sys.argv[1:]\nrunpy.run_path(str(root/'shared/handoff.py'),run_name='__main__')"
        cp=subprocess.run([sys.executable,'-X','utf8','-c',code,'verify'],cwd=out,capture_output=True,text=True,encoding='utf-8');assert cp.returncode==0,cp.stderr
        query=subprocess.run([sys.executable,'-X','utf8','-c',code,'query','--version','kr','--task',tid],cwd=out,capture_output=True,text=True,encoding='utf-8');assert query.returncode==0,query.stderr
        q=json.loads(query.stdout);assert q['tasks'][0]['id']==tid
        local_links=0
        for md in out.rglob('*.md'):
            for href in re.findall(r'\]\(([^)]+)\)',md.read_text(encoding='utf-8')):
                if '://' in href or href.startswith('#'):continue
                target=(md.parent/href.split('#')[0]).resolve()
                assert target.is_relative_to(out.resolve()) and target.exists(),(md,href)
                local_links+=1
        c=json.loads((out/'shared/catalog.json').read_text(encoding='utf-8'));artifact=out/c['artifacts'][0]['path'];raw=artifact.read_bytes();artifact.write_bytes(raw+b'\nCORRUPTION_TEST\n')
        bad=subprocess.run([sys.executable,'-X','utf8','-c',code,'verify'],cwd=out,capture_output=True,text=True,encoding='utf-8');assert bad.returncode!=0;artifact.write_bytes(raw)
        results.append({'task':tid,'zip':zpath.relative_to(ROOT).as_posix(),'zip_bytes':zpath.stat().st_size,'zip_sha256':hashlib.sha256(zpath.read_bytes()).hexdigest(),'original_source_access_denied':True,'query_passed':True,'local_links_verified':local_links,'corruption_detected':True,'verification':json.loads(cp.stdout)})
        assert out.resolve().is_relative_to((ROOT/'validation').resolve());shutil.rmtree(out)
    (ROOT/'validation/release-tests.json').write_text(json.dumps(results,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps(results,ensure_ascii=False))
if __name__=='__main__':main()
