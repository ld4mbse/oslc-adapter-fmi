# Installing OSLC FMI Adapter

## Step 1: Installing OSLC4J


```
git clone http://git.eclipse.org/gitroot/lyo/org.eclipse.lyo.rio.git
cd org.eclipse.lyo.rio
cd org.eclipse.lyo.oslc4j.rio.build
mvn clean install

git clone https://github.com/eclipse/lyo.core.git
cd lyo.core
cd org.eclipse.lyo.oslc4j.build
mvn clean install
```

## Step 2: Installing the OSLC FMI Adapter

```
git clone git clone https://bitbucket.org/koneksys/oslc-adapter-fmi 
cd oslc-adapter-fmi
cd com.koneksys.oslc.adapter.fmi.build
mvn clean install
```

## Step 3: Configuering and running the OSLC FMI Adapter


```
cd oslc-adapter-fmi
cd com.koneksys.oslc.adapter.fmi
mvn tomcat7:run
```

Open URL http://localhost:8686/oslc4jfmi/services/catalog 
